- - ### Implicit conversion

    Implicit conversions are automatically performed when a value is copied to a compatible type. For example:

```
short a=2000;
int b;
b=a;
```

——— 		

### Keyword explicit



On a function call, C++ allows one implicit conversion to happen for each argument. This may be somewhat problematic for classes, because it is not always what is intended. For example, if we add the following function to the last example:

![](https://i.imgur.com/hycHuqo.png)

```C++

```

This may or may not be what was intended. But, in any case, it can be prevented by marking the affected constructor with the `explicit` keyword: