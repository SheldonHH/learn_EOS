#include "../boost/lexical_cast.hpp"
#include <string>
#include <iostream>
 using namespace std;
 using boost::lexical_cast;
 using boost::bad_lexical_cast;

 int main(){

 	// to string / array
 	int s = 23;
 	string str = lexical_cast<string>(s); // convert s from integer to string
 	str = "Message: " + lexical_cast<string>('A') + "="+lexical_cast<string>(34.5); // use the same function convert to string
 	array<char, 64> msg = lexical_cast< array<char, 64> >(23);

 	// from string 
 	s = lexical_cast<int>("3456"); // convert from string
 	try{
 		s = lexical_cast<int>("56.8"); //  bad_lexical_cast
 	}catch(bad_lexical_cast & e){
 		cout << "Exception caught !" << e.what() << endl;
 	}
 	s = lexical_cast<int>("3456yu");	// bad_lexical_cast
 	s = lexical_cast<int>("3456yu", 4);  // only cast the first four letter in the string
 	





 }

// // normal way to convert from string 



// atof: 	to double
// atoi: 	to integer
// atol: 	to long integer
// atoll:	to long long integer



// // convert to string
// stringstream strm;
// strm << int_val;
// string s = strm.str();


// // sscanf() and sprintf() are not safe
// itoa: //not standard funtion


// boost provide safe & convenient and efficient way of doing the conversion