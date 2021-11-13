#include <iostream> 
#include <random> // no lib

int main(){
    std::random_device rd;
    std::mt19937 mersenne(rd());
    
    return 0;
}