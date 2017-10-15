

#### Review:

# &: the address of 	*: value pointed to by



# *: derefence operator , pointer



a variable which **stores the address of another variable** is called a *pointer*

pointer can be used to access the variable that they point to





### Pointers and arrays

The concept of arrays is related to that of pointers. In fact, arrays work very much like pointers to their first elements, and, actually, an array can always be implicitly converted to the pointer of the proper type. For example, consider these two declarations:

```
int myarray [20];
int * mypointer;
mypointer = myarray; // Pointer can be assigned with Array
```



```
myarray = mypointer; array CANNOT be assigned to mypointer
```

```
// more pointers
#include <iostream>
using namespace std;

int main ()
{
  int numbers[5];
  int * p;
  p = numbers;  *p = 10; //p[0] = 10
  p++;  *p = 20; //p[1] = 20
  p = &numbers[2];  //p[0] = the address of numbers[5] 0
  *p = 30;  //p[1] = 30;
  p = numbers + 3;  //
  *p = 40;
  p = numbers;  
  *(p+4) = 50;
  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";
  return 0;
}
```

Pointers and arrays support the same set of operations, with the same meaning for both. The main difference being that pointers can be assigned new addresses, while arrays cannot.

In the chapter about arrays, brackets (`[]`) were explained as specifying the index of an element of the array. Well, in fact these **brackets are a dereferencing operator** known as ***offset operator***. They dereference the variable they follow just as `*` does, but they also add the number between brackets to the address being dereferenced. For example:

```
a[5] = 0;       // a [offset of 5] = 0
*(a+5) = 0;     // pointed to by (a+5) = 0 
```

## Pointer Initilize :

When pointers are initialized, what is initialized is **the address they point to** (i.e., `myptr`), **never** the **value** being pointed (i.e., `*myptr`). 

Assign **"the value that pointer point to"** to **the address of  myvar**



```
int myvar;
int * myptr; // * indicate it is a pointer not a dereference operator
myptr = &myvar;  // a derefence 
// assign "the address that pointer point to"  to  with the address of myvar



//initialize must assign with the ADDRESS they point to, not the VALUE it p
```
##### Invalid: because it 

assign **the value of the pointer** to the **address of the myvar**

```
int myvar;
int * myptr;
*myptr = &myvar; 
```