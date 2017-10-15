#### Pointer to base class

pointer to a derived class is **type-compatible** with a pointer to its **base class**

```C++
// pointer to a derived class 
class Polygon{
    protected:
  		int w, h;
  	public:
  		void set_values(int a, int b){
            w = a; h = b;
        }
};

class R: public Polygon{
    public: 
  		int area(){
            return w*h/2;
        }
};


int main(){
    R rect;
  	P *p1 = &rect; 
  	p1 -> set_values(4,5); // (*p1).set_values(4,5); 
  	rect.set_values(12);
  	cout << rect.area();
}
```

####  Virtual members  = method overriding  / run time poly

virtual member is the member_functions that can be redefined in the derived class. By using the keyword **this** 



virtual member is a member fucntion that can be **redefined** in a derived class, while preserving its calling properties through references.

```C++
class Polygon{ // Polymorphic class
    protected:
  		int w, h;
  	public:
  		void set_values(int a, int b){
            w = a; h = b;
        }
  		virtual int area(){ 
           	return 0;
        }
};

class R: public Polygon{ // Polymorphic class
    public: 
  		int area(){
            return w*h/2;
        }
};



int main(){
    R rect;
  	P *p1 = &rect; 
  	p1 -> set_values(4,5);
  	rect.set_values(12);
  	cout << rect.area();
  	cout << p1 -> area(); // if remove virtual, the area = 0
}
```



non-virtual function also can be redefined in derived class, but **non-virtual** function **cannot** be accessed through **base reference** 

virtual allow **a member of a dervied class** with the same name as the one in the base class to be called by a pointer of base class

a class that **declares** **or** inherits a virtual function is called *polymorphic class



#### Abstract base classes

1. only be used in base classes
2. allowed to have virtual member functions **without definition (known as pure virtual function)**没有braces里面的内容



Classes contains **at least one** pure virtual function are known as **abstract base classes**

Abstract base classes cannot be used to instantiate objects. Therefore, this last abstract 



```C++
class Polygon{
    protected:
  		int w, h;
  	public:
  		void set_values(int a, int b){
            w = a; h = b;
        }
  		virtual int area(void) = 0; // pure virtual function
};


class R : public P{
    public:
  		int area(void){
            return (w*h);
        }
}

int main(){
    R rect;
  	Triangel trgl;
  	Poloygon *p1 = &r; // dereferenced when pointing to objects of derived classes
  	p1 -> set_values(4,5);
  	cout << p1 -> area() << '\n';
} 

```

objects of different but related types are referred to using a unique type of pointer (**polygon***) and the proper member function is called every time, just because they are virtual.

For example, it is even possible for a **member of the abstract base class** Polygon to use the **special pointer** this to access the proper virtual members, even through Polygon itsef has no implementation for this function.





```C++
class Polygon{
  	protected:	
 		int w, h;
  	public:
  		void set_values(int a, int b) {w= a; h = b;}
  		virtual int area() = 0;
  
  // a member of abstract base class can use special pointer this to saccess proper  virtual membesr
  		void printArea(){
            cout << this -> area() << "\n"; 
        }
};

class R: public P{
    public:
  		int area(void){void}
}
```

##### Features can be applied to arrays of objects or dynamically allocated objects

```c++
// dyanmic memory, constructor, initializers and polymorphism

class Polygon{
    protected: 
  		int w, h;
  	public:
  		Polygon(int a, int b) : w(a), h(b){}
  		virtual int area(void) = 0;
}
```

