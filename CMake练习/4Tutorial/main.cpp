#include <iostream>
#include "config.h"  // created by "configuration_file()"
using namespace std;


#ifdef USE_MYMATH
	#include "math/MathFunctions.hpp"
#else
	#include <cmath>
#endif


int main() // argc: # of parameters, argv: array of parameters
{
    double x;
    double result;
    cout << "This program calculate a square root of a certain number." << endl;
    cout << "Please enter a number: " ;
    cin >> x;


  #ifdef USE_MYMATH
   		 printf("Now we use self-defined Math library. \n");
   		 result = squareroot(x);
	#else
	    printf("Now we use the <cmath> library. \n");
	    result = sqrt(x);
	#endif
    	cout << "the square root of the input number x is: " << result << endl;
	    return 0;



}