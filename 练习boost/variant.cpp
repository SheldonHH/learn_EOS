#include "boost/variant.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	// union ，不要忘记在最后一个variable 后面加上一个分号
	union {int i; float f;} u; //can be used to store either an integer or float but not both 
	u.i = 34;
	u.f = 2.3; // u.i is overwritten 

	// in cpp we use class instead of union
	boost::variant<int, string> u1, u2;
	u1 = 2; // int
	u2 = "Hello"; // string
	cout << u1 << " " << u2 << endl;

	u1 = boost::get<int>(u1);  //beware of the type，we have to know the data type
	// string st = boost::get<string>(u1); // throw bad_get， u1 is int not a string
	u1 = "good"; // u1 becomes a string
	u1 = 32; // u1 becomes an int again

	boost::variant<int, string> u3;  
	cout << "u3: " << u3 << endl;  // u3 contains zero
  

	// HOW TO KNOW THE DATA TYPE that stored in the variant
	void Double(boost::variant<int, string> v);
	// use visitor to know the data type stored in the variant
	class DoubleVisitor: public boost:: static_visitor<>{  // functor derived from static_visitor class
	public:
		void operator() (int& i) const{
			i += i;
		}

		void operator()(string& str) const{
			str += str;
		}
	};



 	DoubleVisitor f;
	// u1 = 2;
	// boost::apply_visitor(f, u1);
	// u2 = "Hello";
	// boost::apply_visitor(f, u2);

	//FLEXIBLE AND SAFE (VISITORS & VARIANT)
	std::vector< boost::variant<int, string> > v;
	v.push_back("good");
	v.push_back(23);
	v.push_back("apple");
	v.push_back(123);
 	for (auto x: v){
 		boost::apply_visitor(f, x);
 	}

 	copy(v.begin(), v.end(), ostream_iterator< boost::variant<int, string> >(cout, " ")); // copy belongs to algorithm library



}