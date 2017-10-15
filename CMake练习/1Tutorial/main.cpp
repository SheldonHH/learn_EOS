#include <iostream>
#include <cmath>
using namespace std;

// use Newton method to find a square root of a certain number
double squareroot(double x)
{
    if(x == 0) return 0;
    double res = 1.0;
    double eps = 1e-12;

    while(abs(res*res - x) > eps){
        res = (res + x / res) / 2;
    }
    return res;
}


int main() // argc: # of parameters, argv: array of parameters
{
    int x;
    cout << "This program calculate a square root of a certain number." << endl;
    cout << "Please enter a number: " ;
    cin >> x;
    cout << "the square root of the input number x is: " << squareroot(x) << endl;
    return 0;
}