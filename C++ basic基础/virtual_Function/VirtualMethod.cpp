// Virtual method binded at running time(late-binding)
#include <iostream>
using namespace std;

class base{
public:
	virtual void show(){
		cout << "base show()" << endl;
	}

	void print(){
		cout << "base print()" << endl;
	}
};

class derive: public base{
	void show(){
		cout << "derive non-virtual show()" << endl;
	}
	void print(){
		cout << "derive print()" << endl;
	}
};

int main(){
	base *bptr;
	derive d;
	bptr = &d;

	// virtual function, binded at runtime
	bptr -> show();

	// non-virtual function, binded at compile time
	bptr -> print();

}