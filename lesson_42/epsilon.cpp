#include <iostream>
#include <cmath>

bool approximatelyEqual(const double a, const double b, const double epsilon) {
    return fabs(a - b) <=  ( (fabs(a) - fabs(b) ? fabs(b) : fabs(a) ) * epsilon );
}

bool approximatelyEqualAbsRel(const double a, const double b, const double absEpsilon, const double relEpsilon) {
    //check for equality
    double diff = fabs(a-b);
    if (diff <= absEpsilon)
        return true;
    return diff <= ( ( fabs(a) - fabs(b) ? fabs(b) : fabs(a) ) * relEpsilon );
}

int main(){
    double a(1.0001);
    double b(1.0002);
    std::cout << approximatelyEqual(a, b, 0.0001) << std::endl;
    std::cout << approximatelyEqualAbsRel(a, b, 1e-12, 1e-8) << std::endl;
    return 0;
}