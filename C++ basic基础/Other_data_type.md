http://www.cplusplus.com/doc/tutorial/other_data_types/

Type Alias

#### Two ways to define an alias to abstract programs

inherited from C languages, it use **typedef** as keywords

in C++ **using** keywords

```C++
using field = char[20];		

typedef char* pChar;
```

neither will create new distinct types 



#### Union 

one portion of the memory to be accessed the different data types

declaration is similiar to **struct**. but functionality is totally different 

```c++
union typeName{
    member_type1 member_name1;
  	member_type2 member_name2;
  	member_type3 member_name3;
}objectName;

union mytype_t{
    char c;
  	int i;
  	double d;
}mytype;


union mix_t{
    int l;
  	struct {
        short hi;
      	short lo;
    }s;
  	char [4];
}mix;
```

change one member in one 

![](http://www.cplusplus.com/doc/tutorial/other_data_types/union.png)



deque vector array, 





### Anonoymous Unions (when union is a class of a struct)

```C++
struct book1_t{
    char title[50];
  	char author[50];
  	union{
        float dollars;
      	int yen;
    }price;
} book1;

struct book2_t{
    char title[50];
  	char author[50];
  	union{
        float dollars;
      	int yen;
    }price;
}book2;
```

Enumerated types with enum class

**enum class** **neither** implicitly convertible to **int** **nor** have an **enumerator** **values** of type int, but of the enum type itself, thus preserving type safety. They are declared with **enum class**

Each of the enumerated type of the enum class needs to be scoped into its type

```c++
enum class Colors {black, white, red, green, blue};
Colors myColor;
myColor = Colors:blue;
if(myColor  == Colors::blue) myColor = Colors::red
```

```C++
enum class EyeColor : char {blue, green, brown}	
```

