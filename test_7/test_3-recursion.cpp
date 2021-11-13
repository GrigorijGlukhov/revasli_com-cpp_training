#include <iostream> 
#include <string>

int binarySearch(const int * array, int target, int min, int max) {
    int result = -1;
    int middle = (min+max)/2;
    if ( target == array[middle] ) return middle;
    if ( target < array[middle] ) max = middle;
    else if ( target > array[middle] ) min = middle;
    if ( max-min > 1 ) return binarySearch(array, target, min, max);
    else return result;
}

int main(){
    int array[] = {0, 2, 5, 6, 7, 8, 9, 11, 12, 13};
    
    std::cout << "Enter number: ";
    int x;
    std::cin >> x;
    
    int index = binarySearch(array, x, 0, sizeof(array)/sizeof(array[0]));
    
    std::cout << "\nResult: " << index;
    return 0;
}