double squareroot(double x){
    double eps = 1e-12; //eplision C++
    double res = 1.0;
    while( abs(res*res - x < eps)){
        res = (res + x/res) / 2; 
    }
    return res;
}