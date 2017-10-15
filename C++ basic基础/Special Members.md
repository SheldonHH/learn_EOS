copy assignment 

```C++
C:C(const C&);			// copy constructor
C &operator = (const C&); // copy assignment 

C:~C (); 				// destructor

C &operator= (const C&)// copy assignment
  
C::C (C&&);				//move constructor
C &operator = (C&&)		// move assignment

```





```C++
Six Special members
C:C(); // constructor
C:~C();	// destructor
C:C (const C&)// copy constructor
C &operator= (const C&); // copy assignment

C:C(C&&);	// move constructor
C &operator= (C &&); // move assignment
```



Default Constructor

```C++
// implicitly assin 
class Example {
  public:
    int total;
    void accumulate (int x) { total += x; }/imp
};
```

No-valid default constructor	

```C++
class Example{
 	public:
  		int total;
  		Example2(int inital_value)
        void accumulate(int x) {total += x};
}	

Example2 ex(100); // correct
Example2 ex; //incorrect
```



Default Constructor

necessary clearnup needed by class when its lifetime ends. The classes we have defined in previous chapters did not allocate any resource and thus did not really required any clean up.

the class in the last example allocates **dynamic memory** to store the string it had as data member, it should release the member in the end.  **Take no agruments and return nothing**





```C++
#include <iostream>
#include <string>
using namespace std;

class Example4{
    string* ptr;
  	public:
  	// constructors
  	Example4(): ptr(new string){} // assign 
	Example4( const string& str ) : ptr(new string(str)){} // assign ptr vthe address of str
  	~Example4(){ delete ptr; } // release the dynamic memory
  	// access the content
  	const string& content() const{return *ptr;}
};

int main(){
	Example4 foo;
  	Example4 bar("Example");
  	cout << "bar's content：" << bar.content() << '\n';
}
```

#### Copy Constructor

```c++
MyClass::MyClass (const MyClass&)
```

if a class hass no custom copy nor move constructors(or assignments ) defined, an implicit copy constructor is provided. This copy constructor simply performs a copy of its own members

```C++
Class MyClass{
    public:
  		int a, b; string c;
};

// implicit copy constructor is automatically defined function onlyperforms a shallow copy
Myclass::Myclass (const Myclass& x) : a(x.a), b(x.b), c(x.c){}
```

Shallow Copy: only the pointer value is copied, but not the content itself. for the copy and the original would be sharing a same string object, and at some point(on destruction) bothobjects would try to delete thee same block of memory, probably cuasing the program to crash on runtime.



#### Copy Constructor

```c++
class Example5{
   string *ptr;
   public: 	
  		Example5 (const string& str) : ptr(new string(str)) {}
  		~Example5(){delete ptr;}
  		// copy constructor
  		Example5 (const Example5& x) : ptr(new string(x.content)) {}
  		// access content
  		const string content() const {return *ptr;}
} 	
```



deep copy performed by this copy constructor allocates storage for a new string

```c++
C::C() a();		// constructor
C::~C()	// destructor
C::C (const C&)	// copy constructor
C& operator = (const C&)
  
C::C  (C&&) 
C& operator = (C&&)
  
  // copy constructor
  const E5(const E5 &x) : ptr(new string(x.content())) {}
	// access content()
	const string content()  const { return *ptr}
```

Rvalue reference specified using two ampersand, matches arguments of temporaries of this type

### Move assignment

```C++
class E6{
  E6(const string &str) : ptr(new string(str)) {}
  ~E6() { delete ptr; }
  // move assignment
  E6(E6 &&x) : ptr(x.ptr) { delete }
  
  // move assignment
  E6& operator= (E6 && x){
      	delete ptr;
    	ptr = x.ptr;
    	x.ptr = nullptr;
    	return *this;
  }
  // access content()
	const string& content() const{
        return *ptr;
    }
  // addition
  	E6 operator+(const E6& rhs){
        return E6(content() + rhs.content());
    }
};


// access content()
const string& content() const{
    return *ptr;
}

// addition operator+
const operator+ (const E6& rhs){
    return E6(content()+rhs.content());
}


int main(){
    E6 foo("Exam");
  	E6 bar = E6("pie");
  	foo = foo + bar;
  	cout << "foo's content: "<< foo.content() << endl;
}

```

Compilers already optimize many cases that fromally require a move-construction call in whatis known as **Return Value Optimization**. Most notably. when the value returned by a function is used 

Note that even through **revalue references** can be used for the type of any function parameter, it is seldom useful for uses other than the move constructor. 

# Six special members are implicitly declared on classes



not all special member functions are implicitly defined in the same cases. 



```C++
class R{
  int w, h;
 	public:
  		R(int x, int y) : w(x), h(y){}
  		
}
```

