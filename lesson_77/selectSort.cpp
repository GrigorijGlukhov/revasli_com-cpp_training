#include <iostream> 
#include <algorithm>

int main(){
    int array[] = {53, 27, 84, 35, 12, 41, 76};
    int arrayLength = sizeof(array) / sizeof(array[0]);
    
    int smallestIndex;
    for(int arrayIndex = 0; arrayIndex < arrayLength-1; ++arrayIndex)
    {
        smallestIndex = arrayIndex;
        for(int searchIndex = arrayIndex+1; searchIndex < arrayLength; ++searchIndex)
        {
            //can be reversed with > symbol
            if(array[smallestIndex] > array[searchIndex])
            smallestIndex = searchIndex;
        }
        std::swap(array[arrayIndex], array[smallestIndex]);
    }
    
    for(int count=0; count < arrayLength; ++count)
        std::cout << array[count] << " ";
    return 0;
}