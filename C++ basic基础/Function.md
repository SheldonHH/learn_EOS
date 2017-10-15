

##### Arguments pased by value and by reference

in some cases, it may be useful to access an external variable from within a function, todo that, arguments can be passed by referecne. 

causing the variables used as arguments to actually be modified by the call

```c++
void duplicate(int& a, int& b, int& c){
    a*=2;
  	b*=2;
  	c*=2;
}

int main(){
    int x = 3, y = 4, z = 7;
  	duplicate(x, y, z);
  	cout << "x =" << x <<" y=" << endl;
	return 0;
}
```

To gain access to its argument, the function declares it

When a variable is passed by **reference**, what is passed is no longer a copy, but the variable itself

ampersand &





#### Efficiency consideration and const reference

if parameter is a large compound value like **string**, it may result on certain overhead

```c++
string concate(string a, string b){
    return a+b;
}
```



no need to copy large quantities of data  Arguments by reference do not required a copy



```C++
// functions with reference parameters are generally perceived as functions that modify the arguments passed
string concate (string& a, string& b){
    return a+b;
}
```

```C++
// qualifying parameters are const, forbidden to modify the values of neither a nor b,, but can access their values as refernces, without having to make actual copies of the strings
string concate (const string &a, const string &b){ // qualifying parameters as const
    return a+b;
}
```

const reference popular among the compounded data in 





#### Inline functions

calling functions will incur overhead (stack arguements, jumps) thus for very short function, it may 

be more efficient to simply insert.

**to be expanded inline** instead of **performing a regular call**

Most compilers already optimize code to generate inline functions when they see an opportunity to improve efficiency, **even if not marked** with the `line` specifier.

optimization is a task delegated to the compilers.

#### Default value in parameters

```C++
int divide(int a, int b = 2){
    int r;
  	r = a/b;
  	return (r);
}

int main(){
    cout << divide(12) << end;
  	cout << divide(12, 3) << endl;
}
```

#### Declaring functions

The same applies to functions. Functions cannot be called before they are declared. That's why 





```C++
// Recursivity
long factorial(long a){
   	if(a > 1) a*factorial(a-1);
  	else return 1;
}


int main(){
   	long number = 9;
  	cout << "number: " << factorial(a) << endl;
  	return 0;
}
```

















