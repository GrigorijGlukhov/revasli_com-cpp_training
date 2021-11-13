// using const with classes

#include <iostream> 

class Date {
    int m_day;
    int m_month;
    int m_year;
public:
    Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}
    //int getDay() {return m_day; } // error if obj used as const &
    int getDay() const {return m_day; } // ok
};

void printDate(const Date & date) { // object converts to const object
    std::cout << date.getDay() << '\n';
}

int main(){
    Date date1(10, 11, 2021);
    printDate(date1); // converts to const object
    return 0;
}