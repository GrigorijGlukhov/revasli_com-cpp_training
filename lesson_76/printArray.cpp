#include <iostream> 

int main(){
    int array[] = {7, 2, 6, 3, 4, 1, 5, 8, 9};
    
    int arrayLength = sizeof(array) / sizeof(array[0]);
    
    for(int count=0; count < arrayLength; ++count) {
        std::cout << array[count] << " ";
    }
    
    return 0;
}