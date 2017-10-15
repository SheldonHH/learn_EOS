# 首先找到最近的一个插入Keybase 的哈希值
# Keybase经常被push到merkle_tree 的根部，并且使用1HUCBSJeHnkhzrVKVjaVmWg2QtZS1mdfaz作为公钥进行签署


from  urllib.request import urlopen
import ssl
import json
from_addr = "1HUCBSJeHnkhzrVKVjaVmWg2QtZS1mdfaz"
uri       = "https://blockchain.info/address/%s?format=json" % (from_addr)  # %s是string formatting syntax
to_addr   = json.load(urlopen(uri))['txs'][0]['out'][0]['addr'] 
to_addr1 = json.load(urlopen(uri))

print (to_addr)

print (to_addr1)


