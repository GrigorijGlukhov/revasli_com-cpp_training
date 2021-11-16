// friend classes

#include <iostream>
#include <string>

class Values
{
    int m_iValue;
    double m_dValue;
public:
    Values(int iValue, double dValue): m_iValue(iValue), m_dValue(dValue) {}
    friend class Display;
};

class Display
{
    bool m_bShowFirst;
public:
    Display( bool value = true ) : m_bShowFirst(value) {}
    void showValue( Values & values )
    {
        if ( m_bShowFirst )
            std::cout << "Int value: " << values.m_iValue << '\n';
        else
            std::cout << "Double value: " << values.m_dValue << '\n';
    }
};

int main()
{
    Values value(10, 20.0);
    Display display(1);
    display.showValue(value);
    return EXIT_SUCCESS;
}
