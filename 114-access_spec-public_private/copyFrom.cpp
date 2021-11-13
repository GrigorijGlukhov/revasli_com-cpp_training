#include <iostream> 


class DateClass {
    int m_day;
    int m_month;
    int m_year;
    public:
    void set(int day, int month, int year) {
        m_day = day;
        m_month = month;
        m_year = year;
    }
    void print() {
        std::cout << "Date: " << m_day << "/" << m_month << "/" << m_year << "\n";
    }
    void copyDateFrom(const DateClass & b) {
        m_day = b.m_day;
        m_month = b.m_month;
        m_year = b.m_year;
    }
    //for test 2
    bool isEqual(const DateClass & b) {
        if ( m_day == b.m_day && m_month == b.m_month && m_year == b.m_year ) return true;
        return false;
    }
};

int main(){
    
    DateClass d1;
    d1.set(11, 11, 2021);
    DateClass d2;
    d2.copyDateFrom(d1);
    d2.print();
    //for test 2
    std::cout << d1.isEqual(d2);
    
    return 0;
}