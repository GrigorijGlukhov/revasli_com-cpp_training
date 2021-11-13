#include <iostream> 
#include <string>

int binarySearch(const int * array, int target, int min, int max) {
    int result = -1;
    int cnt = 30; // anti inf loop
    do {
        int middle = (min+max)/2;//index
        int val = *(array+middle); //get current value
        std::cout << val << " min/max: " << min << " " << max << "\n";
        if ( val == target) return val;
        if ( target > val ) min = middle;
        else if ( target < val ) max = middle;
        if ( max-min == 1 ) return -1;
    } while (cnt--);
    return result;
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