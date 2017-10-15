

### Tie: // unpacking tuple into variables

```
// packing/unpacking tuples
#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::make_tuple, std::tie

int main ()
{
  int myint;
  char mychar;

  std::tuple<int,float,char> mytuple;

  mytuple = std::make_tuple (10, 2.6, 'a');          // packing values into tuple

  std::tie (myint, std::ignore, mychar) = mytuple;   
  // unpacking tuple into variables

  std::cout << "myint contains: " << myint << '\n';
  std::cout << "mychar contains: " << mychar << '\n';

  return 0;
```





参考链接：http://www.cplusplus.com/reference/tuple/make_tuple/

```
// make_tuple example
#include <iostream>
#include <tuple>
#include <functional>

int main()
{
  auto first = std::make_tuple (10,'a');             // tuple < int, char >

  const int a = 0; int b[3];                         // decayed types:
  auto second = std::make_tuple (a,b);               // tuple < int, int* >

  auto third = std::make_tuple (std::ref(a),"abc");  // tuple < const int&, const char* >

  std::cout << "third contains: " << std::get<0>(third);
  std::cout << " and " << std::get<1>(third);
  std::cout << std::endl;

  return 0;
}
```







# Get<1>()

http://www.cplusplus.com/reference/tuple/get/





## <header> Tuple

Tuples are objects that pack elements of **-possibly- different types** together in a single object, just like [pair](http://www.cplusplus.com/pair) objects do for pairs of elements, but generalized for any number of elements.

Conceptually, they are similar to plain old data structures (C-like structs) but instead of having named data members, its elements are **accessed by their order** in the [tuple](http://www.cplusplus.com/tuple).

The selection of particular elements within a [tuple](http://www.cplusplus.com/tuple) is done at the template-instantiation level, and thus, it must be specified at compile-time, with helper functions such as [get](http://www.cplusplus.com/get) and [tie](http://www.cplusplus.com/tie).

### get，tie





The [tuple](http://www.cplusplus.com/tuple) class is closely related to the [pair](http://www.cplusplus.com/pair) class (defined in header <utiliy>): **Tuples can be constructed from pairs**, an**d pairs can be treated as tuples for certain purposes**.

[array](http://www.cplusplus.com/array) containers also have certain **tuple-like** functionalities.



# <Class Template> Tuple

# <public member function> Tuple









