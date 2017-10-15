#include "boost/optional.hpp" // boost optional class
using namespace std;

deque<char> de;

boost::optional<char> get_async_data(){ // get last element from deque and return it as char
	if(!de.empty()){
		return boost::optional<char>(queue.back()); //initialize the last item of the queue
		// return de.back();
	}else{
		return '\0'; // return null value which is a valid char
	}
}

int main(){
	boost::variant<nullptr_t, char> v; // return value should be either nullptr_t, or a char
	boost::optional<char> op;  // op is uninitialized,  no char is constructed
	

	op = 'A'; 
	op.get_async_data();
 
	// if(!op){ // if(op != 0)
	// 	cout << "No data is available" << endl;
	// }else{
	// 	cout << "op contains " << op.get() << endl;  // crash if op is not initalized 
	// 	cout << "op contains " < < *op << endl; // optional can be used in a similiar way of pointer 
	// }

	op.reset(); // reset op to uninitialized state
	cout << op.get_value_or('z') << endl; // return 'z' if op is empty()
	char* p = op.get_pointer(); // return null if op is empty






	struct A{string name; int value;};

	A a;
	boost::optional<A> opA0; // constructor of A is not called
	boost::optional<A> opA(a); // a is COPY CONSTRUCTED  into opA

	cout << opA->name << " " << opt->value << endl; // opt can be used in a similiar way of a pointer 
	// Pointer:
	boost::optional<A*> opAP(&a);
	(*opAP) -> name = "Bob";


	// Reference:
	boost::optional<A&> opAR(a);
	opAR -> name = "Bob"; // this also changes a.name

	// Relational operator (comparsion)
	boost::optional<int> i1(1);  // initalized to 1
	boost::optional<int> i2(9); 
	if(i1 < i2){
		
	}

 
} // more powerful interface



