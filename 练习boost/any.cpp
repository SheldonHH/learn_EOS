#include "boost/variant.hpp" 
#include <iostream>
#include <vector>
#include "boost/any.hpp" // be able to store any types of data
using namespace std;

int main(){
	boost::any x, y, z;
	x = string("hello");
	x  = 2.3;
	y = 'y';
	z = 'z';



	// data type of any can only be checked in the run time
	// variant can check data type in the compile time while using "visitor" 
	if(x.empty()){
		cout << "x is empty" << endl; 
	}

	if(y.type() == typeid(char)){
		cout << "y is a char type" << endl;
	}



	// cout << y << endl; // + is not overloaded for variantt , and left_shift operator is not overloaded with 'any' type

	// any_cast<>()  is similiar to get<>()  for variant
	// any_cast<> return a copy of the data
	// get<>() return a reference of the data
	cout << boost::any_cast<char> (y) << endl; // return a copy of y's data which is 'z'， 
	cout << boost::any_cast<double> (x) << endl; // return a copy of x's data which is 2.3
	// cout << boost::any_cast<int> (x) << endl;  // bad_any_cast
	// cout << boost::any_cast<float>(x) << endl; // bad_any_cast exception


	// variant cannot be empty;
		boost::variant<string, int> var;
		cout << "var: "<< var << endl;
	//


	int i; 
	boost::any p = &i;
	int* pInt = boost::any_cast<int*>(p); // convert p a pointer


	vector<boost::any> m;
	m.push_back(2);
	m.push_back('a');
	m.push_back(p);  // another any of integer pointer
	m.push_back(boost::any()); // empty() as the placeholder

	struct Property{
		string name;
		boost::any value;
	};

	vector<Property> properties;




}
