| Expression | What is evaluated                        | Equivalent |
| ---------- | ---------------------------------------- | ---------- |
| `a.b`      | Member `b` of object `a`                 |            |
| `a->b`     | Member `b` of object pointed to by `a`   | `(*a).b`   |
| `*a.b`     | Value pointed to by member `b` of object `a` | `*(a.b)`   |

**Namespaces**

Cplusplus给出了非常好的解释

参考链接：http://www.cplusplus.com/doc/oldtutorial/namespaces/



Namespaces allow to group entities like classes, objects and functions **under a name**. This way the global scope can be divided in **"sub-scopes"**, each one with its own name.



The keyword `using` is used to introduce a name from a namespace into the current declarative region. For example:

```
int main () {
  using first::x;
  using second::y;
  cout << x << endl;
  cout << y << endl;
  cout << first::y << endl;
  cout << second::x << endl;
  return 0;
}
```



```
int main () {
  {
    using namespace first;
    cout << x << endl;
  }
  {
    using namespace second;
    cout << x << endl;
  }
  return 0;
}
```
![](http://upload-images.jianshu.io/upload_images/3866441-a8fa5aa955ecfb74.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


## struct 和 pointer

[data structure](http://www.cplusplus.com/doc/tutorial/structures/) is a group of data elements grouped together under one name. 参考cpluplus: [http://www.cplusplus.com/doc/tutorial/structures/](http://www.cplusplus.com/doc/tutorial/structures/)



1. clearly differenitiate between the **type name** (`product`), and what is an **object of this type** (`apple`, `banana`, and `melon`). 

![](http://upload-images.jianshu.io/upload_images/3866441-f31cd42755993da6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

1. dot (`.`) between the object name and the member name.

   ![](http://upload-images.jianshu.io/upload_images/3866441-ea9da1ba358fb354.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



3. ​




# 关于 eos.cpp


eos.cpp 位于`eos/contracts/eos`内



![](http://upload-images.jianshu.io/upload_images/3866441-16a0b1276a276a8a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)