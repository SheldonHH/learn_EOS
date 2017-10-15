#include <iostream>
#include <cmath>
#include "math/MathFunctions.hpp"

using namespace std;


int main() // argc: # of parameters, argv: array of parameters
{
    int x;
    cout << "This program calculate a square root of a certain number." << endl;
    cout << "Please enter a number: " ;
    cin >> x;
    cout << "the square root of the input number x is: " << squareroot(x) << endl;
    return 0;
}