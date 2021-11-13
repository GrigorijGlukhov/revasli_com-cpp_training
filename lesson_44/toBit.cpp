#include <iostream> 

int main(){
    int a(128);
    int input(94); //user input simulation
    
    while(a) {
        std::cout << a << " - ";
        //compare values 
        if ( input >= a ) {
            std::cout << 1;
            input -= a;
        }
        else
            std::cout << 0;
        std::cout << "\n";
        
        a = a>>1;
    }
    return 0;
}