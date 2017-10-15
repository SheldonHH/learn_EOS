// access object via pointer to object
Foo *foo = new Foo();
foo -> member_var = 10;
foo -> member_func();


// access object via object instance / class reference
Foo foo;
foo.member_var;
foo.member_func();


// accessing static variable/methods of class/struct or namespace
Foo foo;
foo::static_method();
int max_int = std::numeric_limits<int>::max();






// 双冒号的使用

class CA{
public:
	int car_var;
	int add(int a, int b);
	int add(int a);
};


int CA::add(int a, int b){
	return a + b;
}


int CB::add(int a){
	return a + ::car_var;
}


