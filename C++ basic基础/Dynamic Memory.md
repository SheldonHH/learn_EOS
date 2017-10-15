Dynamic memory allocate two operator new and delete





```
pointer = new type; // one single element of type type
pointer = new type [number_of_elements]; // block of elements of type type
```



The first expression is used to allocate memory to contain **one single element** of type `type`. The second one is used to allocate **a block (an array) of elements** of type `type`, where `number_of_elements` is an integer value representing the amount of these. For example:



![](http://www.cplusplus.com/doc/tutorial/dynamic/dynamic.png)

**first element pointed to by** foo can be accessed either **foo[0]** or ***foo**

The dynamic memory requested by our program is allocated by the system from the **memory heap.**



### nothrow

The other method is known as **`nothrow`**, and what happens when it is used is that when a memory allocation fails, **instead of throwing a `bad_alloc` exception or terminating the program**, the pointer returned by `new` is a *null pointer*, and the program continues its execution normally.

```
foo = new (nothrow) int [5];
```

In this case, if the allocation of this block of memory fails, the failure can be detected by checking if `foo` is a null pointer:

```
int * foo;
foo = new (nothrow) int [5];
if (foo == nullptr) {
  // error assigning memory. Take measures.
}
```



## Delete



First expression releases the memory of **a single element** allocated by using **`new`** 

Second expression releases the memory of block of elements in brackets[]

the memory passed to `delete` shall either be a memory block or null pointer