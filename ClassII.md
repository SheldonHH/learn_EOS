#### Static members

a class can contain static membes, either data or function

static data members: **class variable**, because **only one unique value** for all the objects of the same class. Their content is not diffferent from one object of this class to another



For example, it may be used for a variable within a class that contain a counter with the number of objects of thatclass are 

Static members enjoy class scope. For that reason, to avoid declare more than one time, we can only include in **prototype (its declaration)** but not in its **definition / initialization**

In order to initialize a static data-member, we must include a formal **definition** outside the class, in the global scope, as in the previous example

```C++
class CD{
    public;
  		static int n;
  		CD() { n++; };
  		~CD() { n--; };
};

int CD::n=0;

int main(){
    CD a; 
  	CD b[5];
  	CD *c = new CD;
  	cout << a.n << endl;
  	cout << CD::n << endl;
}
```





#### Keyword this

pointer to the object whose member function is being executed. It is a pointer to the object itself

```C++
// this
#include <iostream>
using namespace std;

class CD{
  public:
  	int istime(CD &param); 
};

int CD::istime(CD &param) {
    return (&param == this);
}

int main(){
    CD a;
  	CD *b = &a; // assignment operator, not dereference pointer
  	(b -> istime(a)) ? (cout << "&a is b") :( cout << "小急急急");
}
```



use **operator=** return **objects by reference** (avoding the use of **temporary** objects)

```C++
CV& CV::operator= (const CV& param){
    x = param.x;
  	y = param.y;
  	return *this;
}
```



