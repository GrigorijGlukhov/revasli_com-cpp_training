#include <iostream> 

int GetValue() {
    int a;
    std::cout << "Enter a number from 1 to 9: ";
    std::cin >> a;
    if (std::cin.fail()) { // check for wrong type
        std::cin.clear(); // clear input in cin
        std::cin.ignore(32767, '\n'); // delete rest of symbols
    }
    else
        return a;
}

int main(){
    int array[] = {7, 2, 6, 3, 4, 1, 5, 8, 9};
    
    int arrayLength = sizeof(array) / sizeof(array[0]);
    int number = GetValue();
    for(int count = 0; count < arrayLength; ++count) {
        if(array[count] == number) {
            std::cout << "Your number in array by index: " << count;
        }
         
    }
    
    
    return 0;
}