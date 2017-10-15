#include "../boost/lexical_cast.hpp"
#include <iostream>
#include <string> //      stod: convert string to double 
// #include <stdlib.h> // atof: convert string to double
// #include <stdio.h>
#include <cmath>
// #include "config.h"  // created by "configuration_file()"
using namespace std;
using boost::lexical_cast;



int main(int argc, char *argv[]) // argc: # of parameters, argv: array of parameters
{
      

    double x;
    double result;
    if (argc < 2){
        printf("Please enter a valid number \n");
        return 1;
    }


    x = lexical_cast<double>(argv[1]);
    // cout << "This program calculate a square root of a certain number." << endl;
    // cout << "Please enter a number: " ;


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