#include <iostream> 
#include <algorithm>



int main(){
    int array[] = {7, 1, 9, 2, 8, 3, 6, 4, 5};
    //int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrayLength = sizeof(array) / sizeof(array[0]);
    unsigned int iterations = 0;
    bool sorted;
    
    for(int arrayIndex = 0; arrayIndex < arrayLength; ++arrayIndex) {
        for(int sortIndex = 0; sortIndex < arrayLength-arrayIndex-1; ++sortIndex) {
            sorted = false;
            if (array[sortIndex] > array[sortIndex+1]) {
                std::swap(array[sortIndex], array[sortIndex+1]);
                ++iterations;
                sorted = false;
            }
            if (sorted)
                break;
        }
    }
    for(int count=0; count < arrayLength; ++count)
        std::cout << array[count] << " ";
    std::cout << "\nIterations: " << iterations;
    return 0;
}