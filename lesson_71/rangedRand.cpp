//not work propertly

#include <iostream> 
#include <cstdlib>
#include <ctime>

 int GetRandomRange(int min, int max) {
     static const double fraction = 1.0 / (static_cast<double>(32768) + 1.0);
     return static_cast<int>(rand() * fraction * (max - min + 1) + min);
 }
int main(){
    std::cout << GetRandomRange(1, 6);
    return 0;
}