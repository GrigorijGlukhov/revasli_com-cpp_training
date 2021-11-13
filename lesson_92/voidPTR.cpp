#include <iostream> 

int main(){
    int val = 7;
    void *ptr = &val;
    int *intPtr = static_cast<int*>(ptr);
    std::cout << *intPtr;
    
    return 0;
}