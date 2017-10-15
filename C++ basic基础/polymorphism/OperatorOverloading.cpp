// Example of '+'  overriding
#include "stdc++.hpp"
using namespace std;

// Base Class
class Parent{
public:
	void print(){
		cout << "This is Parent class. " << endl;
	}
};

class Child: public Parent{
public:
	void print(){
		cout << "This is private class" << endl;
	}
};


int main(){
	Parent obj1;
	Child obj2 = Child();
	// obj1 call parent print() function
	obj1.print();
 	// obj2 override the print function in Parent
	obj2.print();
	return 0;
}


