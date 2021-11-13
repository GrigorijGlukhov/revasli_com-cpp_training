#include <iostream> 
#include <cmath>

int main(){
    const int daysInYear(365);
    double days[daysInYear];
    
    for(int eachDay=0; eachDay<daysInYear;++eachDay)
        days[eachDay] = std::sin(eachDay/36);
        
    for(int eachDay=0; eachDay<daysInYear;++eachDay)
        std::cout << days[eachDay] << " ";
    return 0;
}