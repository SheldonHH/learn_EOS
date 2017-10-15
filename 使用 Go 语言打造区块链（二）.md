

# 使用 Go 语言打造区块链（二）





#### 介绍

在上一篇文章中，我们构建了一个非常简单的数据结构，这是块链数据库的本质。 而且我们可以用它们之间的链式关系向它添加区块：每个区块与前一个链接。 唉，然而在现实中添加一个区块添加到链是艰巨的工作。

#### 工作证明

块链的一个关键思想是，必须通过工作证明才能将数据放入其中。这是一个艰巨的工作，使块链安全和一致。此外，这笔辛苦的工作也得到了奖励（这是人们获得采矿硬币的方式）。

这种机制与现实生活中的机制非常相似：人们必须工作获酬劳励并维持生命。在网络中，网络的一些参与者（矿工）努力维持网络，为其添加新的块，并为他们的工作获得奖励。作为其工作的结果，块以安全的方式并入到块链中，这保持了整个块链数据库的稳定性。值得注意的是，完成工作的人必须证明这一点。

这个整体“努力工作和证明工作价值”机制被称为工作证明。这很难因为它需要很多的计算能力：即使是高性能的计算机也不能很快的完成。此外，这项工作的难度不时增加，以保持新的块率每小时大约6个块。在比特币，这样的工作的目标是找到一个块的哈希，满足一些要求。这是散列，作为证明。因此，找到证据是实际工作。

最后要注意的事情。工作证明算法必须满足要求：**做完工作不易完成，证明工作容易完成**。证明通常交给非工作者，所以对他们来说，验证它不应该花太多的时间。







#### 哈希算法加密

在本文中，我们将讨论哈希值。 如果你熟悉这个概念，你可以跳过这个部分。

哈希是获取指定数据的哈希值的过程。 哈希值是对其计算的数据的唯一表示。 哈希函数是一个获取任意大小的数据并产生固定大小的哈希的函数。 以下是哈希的一些主要功能：

- 原始数据无法从哈希值恢复。 因此，散列不是加密。
- 数据只能有一个哈希值，散列是唯一的。
- 更改输入数据中的一个字节将导致完全不同的散列。

![](https://jeiwan.cc/images/hashing-example.png)

哈希函数被广泛用于检查数据的一致性。在区块链中，使用哈希来保证块的一致性。 哈希算法的输入数据包含前一个块的哈希值，从而使得已经生成的链难以修改之前产生的区块（或至少相当困难）：必须重新计算其后的所有块的哈希值。

#### 哈希现金 、 Hashcash 

比特币使用Hashcash，哈希现金的发明最初是为防止电子邮件垃圾邮件而开发的。它可以分为以下几个步骤：

1. 获取公开的数据（在电子邮件的情况下，它是接收者的电子邮件地址;在比特币的情况下，它是块标题）。
2. 添加一个计数器。计数器从0开始。
3. 获取`数据+计数器`组合的散列。
4. 检查哈希值是否符合要求。
   1. 如果满足要求，结束过程。
   2. 如果不满足要求，增加计数器并重复步骤3和4。

因此，这是一个强力算法：您更改计数器，计算一个新的哈希，检查它，增加计数器，计算哈希等。这就是为什么它在计算上是昂贵的。

现在让我们看看一个哈希必须满足的要求。在原来的Hashcash实现中“哈希的前20位必须是零”。然而在比特币中，哈希要求是不时进行调整的，因为尽管计算能力随着时间的推移而增加，越来越多的矿工加入网络，因此设计必须**每10分钟生成一个块**。

为了演示这个算法，我从前面的例子中获取了数据（“我喜欢甜甜圈”），并发现一个以0个零字节开头的哈希：



##### 编写代码

> 程序员小提醒：go和python都是不用加分号的语言

好的，我们完成了理论，让我们编写代码！ 首先，我们来定义挖掘的难度：

```go
const targetBits = 24
```



In Bitcoin, “target bits” is the block header storing the difficulty at which the block was mined. We won’t implement a target adjusting algorithm, for now, so we can just define the difficulty as a global constant.

24 is an arbitrary number, our goal is to have a target that takes less than 256 bits in memory. And we want the difference to be significant enough, but not too big, because the bigger the difference the more difficult it’s to find a proper hash.

在比特币中，“目标位（target bit）”是存储块被挖掘的困难的块头。 我们现在不会实现目标调整算法，所以我们可以将难度定义为**全局常数**。

24是一个任意数字，我们的目标是在内存中占用**少于256位**的目标。 而且我们希望差异足够大，但不要太大，因为差异越大，找到合适的哈希越难。

```go
type ProofOfWork struct {
	block  *Block 
	target *big.Int //定义目标位
}

func NewProofOfWork(b *Block) *ProofOfWork {
	target := big.NewInt(1)
	target.Lsh(target, uint(256-targetBits))  //左移256个 target bits位

	pow := &ProofOfWork{b, target}

	return pow
}
```

这里创建保存指向块的指针的**工作证明**结构和指向目标的指针。 “目标”是上一段所述要求的另一个名称。 我们使用一个大整数，因为我们将**哈希与目标**进行比较：我们将哈希转换为一个大整数，并检查它是否小于目标。

> big: https://golang.org/pkg/math/big/

在新的工作证明的函数中，我们初始化一个值为1的big.Int，并将其左移256个 - targetBits位。 256是SHA-256哈希的长度，以比特为单位，它是我们要使用的SHA-256散列算法。 目标的十六进制表示为：

```
0x10000000000000000000000000000000000000000000000000000000000
```

它在内存中占用29个字节。 这是与以前的例子中的哈希的比较：

```
0fac49161af82ed938add1d8725835cc123a1a87b1b196488360e58d4bfb51e3
0000010000000000000000000000000000000000000000000000000000000000
0000008b0f41ec78bab747864db66bcb9fb89920ee75f43fdaaeb5544f7f76ca
```

**第一个哈希（以“我喜欢甜甜圈”计算）**大于目标，**因此它不是有效的工作证明**。 第二个哈希（以“我喜欢甜甜圈ca07ca”计算）小于目标，因此这是一个有效的证明。

您可以将目标视为范围的上限：如果**数字（哈希）低于边界，则它是有效的**，反之亦然。 降低边界将导致有效数量减少，因此找到有效数量所需的工作更加困难。

现在，对数据进行哈希处理。

```go
func (pow *ProofOfWork) prepareData(nonce int) []byte {
	data := bytes.Join(
		[][]byte{
			pow.block.PrevBlockHash,
			pow.block.Data,
			IntToHex(pow.block.Timestamp),
			IntToHex(int64(targetBits)),
			IntToHex(int64(nonce)),
		},
		[]byte{},
	)

	return data
}
```

我们只是将块区域与目标和随机数合并。 nonce这里是从上面的Hashcash描述的计数器，这是加密术语。

好的，所有的准备工作都完成了，我们来实现PoW算法的核心：

```go
func (pow *ProofOfWork) Run() (int, []byte) {
	var hashInt big.Int
	var hash [32]byte
	nonce := 0

	fmt.Printf("Mining the block containing \"%s\"\n", pow.block.Data)
	for nonce < maxNonce {
		data := pow.prepareData(nonce) // 准备数据
		hash = sha256.Sum256(data) // SHA-256加密
		fmt.Printf("\r%x", hash)
		hashInt.SetBytes(hash[:])  // 讲hash转换成Big Integer

		if hashInt.Cmp(pow.target) == -1 {
			break
		} else {
			nonce++
		}
	}
	fmt.Print("\n\n")

	return nonce, hash[:]
}
```

首先，我们初始化变量：hashInt是哈希的整数表示; nonce是柜台。 接下来，我们运行一个“无限”循环：它受限于maxNonce，它等于math.MaxInt64; 这样做是为了避免可能的随机数溢出。 虽然我们的PoW实施的难度太低，以至于防止溢出，但最好是进行此检查，以防万一。

在循环中我们：

- 准备数据


- 用SHA-256进行哈希。
- 将散列转换为大整数。
- 将整数与目标进行比较。

 现在我们可以**删除Block**的**SetHash**方法并修改**NewBlock**函数：

```go
func NewBlock(data string, prevBlockHash []byte) *Block {
	block := &Block{time.Now().Unix(), []byte(data), prevBlockHash, []byte{}, 0}
	pow := NewProofOfWork(block)
	nonce, hash := pow.Run()

	block.Hash = hash[:]
	block.Nonce = nonce

	return block
}
```

Here you can see that `nonce` is saved as a `Block` property. This is necessary because `nonce` is required to verify a proof. The `Block` structure now looks so:

```go
type Block struct {
	Timestamp     int64
	Data          []byte
	PrevBlockHash []byte
	Hash          []byte
	Nonce         int
}
```

验证**工作证明**

```go
func (pow *ProofOfWork) Validate() bool {
	var hashInt big.Int

	data := pow.prepareData(pow.block.Nonce)
	hash := sha256.Sum256(data)
	hashInt.SetBytes(hash[:])

	isValid := hashInt.Cmp(pow.target) == -1

	return isValid
}
```

主函数代代码再次检查

```go
func main() {
	...

	for _, block := range bc.blocks {
		...
		pow := NewProofOfWork(block)
		fmt.Printf("PoW: %s\n", strconv.FormatBool(pow.Validate()))
		fmt.Println()
	}
}
```



#### 结论

我们的块链是一个更接近其实际架构的一步：添加块现在需要努力工作，因此挖掘是可能的。 但是它仍然缺乏一些关键的特征：块链数据库不是持久的，没有钱包，地址，交易，没有共识机制。 所有这些我们将在以后的文章中实现的，现在，开采开采！

##### 链接：

> 1. [源代码，Full source codes](https://github.com/Jeiwan/blockchain_go/tree/part_2)
> 2. [哈希算法，Blockchain hashing algorithm](https://en.bitcoin.it/wiki/Block_hashing_algorithm)
> 3. [工作证明，Proof of work](https://en.bitcoin.it/wiki/Proof_of_work)
> 4. [哈希现金，Hashcash](https://en.bitcoin.it/wiki/Hashcash)




