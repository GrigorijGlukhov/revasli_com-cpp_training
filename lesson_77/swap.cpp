#include <iostream> 
#include <algorithm>

int main(){
     int a(1);
     int b(2);
     
     std::cout << "Before swap: a = " << a << ", b = " << b << "\n";
     std::swap(a, b);
     std::cout << "After swap: a = " << a << ", b = " << b << "\n";
    
    return 0;
}