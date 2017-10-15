## Pointer Arithmetics



To conduct arithmetical operations on pointers is a little different than to conduct them on regular integer types. To begin with, only addition and subtraction operations are allowed; the others make no sense in the world of pointers. But both addition and subtraction have a slightly different behavior with pointers, according to the size of the data type to which they point.

When fundamental data types were introduced, we saw that types have different sizes. For example: **`char` always has a size of 1 byte**, `short` is generally larger than that, and `int` and `long` are even larger; the exact size of these being dependent on the system. For example, let's imagine that in a given system, **`char` takes 1 byte, `short` takes 2 bytes, and `long` takes 4.** 

Four combination of prefix and suffix

Essentially, these are the **four possible combinations of the dereference operator** with both the prefix and suffix versions of the increment operator (the same being applicable also to the decrement operator):



```
*p++   // same as *(p++): increment pointer, and dereference unincremented address
*++p   // same as *(++p): increment pointer, and dereference incremented address
++*p   // same as ++(*p): dereference pointer, and increment the value it points to
(*p)++ // dereference pointer, and post-increment the value it points to 
```

*p++: increment the address of 





*p++ = *(p++): increment pointer and deference the 

(*p)++: dereference pointers, post-increment the **value** 