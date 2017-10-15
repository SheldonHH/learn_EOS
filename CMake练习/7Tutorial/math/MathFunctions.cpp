#include <cmath>
// #include <cstdlib>

using namespace std;
double squareroot(double x){
	double res = 1.0;
	double eps = 1e-12;
	while(abs(res * res - x) > eps){
		res = (res + x/res) / 2;
	}

	return res;
}