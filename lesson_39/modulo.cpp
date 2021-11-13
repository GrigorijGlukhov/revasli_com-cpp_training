#include <iostream> 

bool isEven(const int &value) {
    return (value % 2) == 0;
}

int main(){
    int count(1);
    
    while(count != 100) {
        if (isEven(count))
            std::cout << count << " ";
        if (count % 20 == 0)
            std::cout << "\n";
        count++;
    }
    
    return 0;
}