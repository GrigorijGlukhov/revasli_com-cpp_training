#include <iostream> 

struct Str {
    int a;
};

int main(){
    Str *arr = new Str(5);
    
    std::cout << arr->a << "\n";
    
    return 0;
}