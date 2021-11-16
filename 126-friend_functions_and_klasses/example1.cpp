// using friend function

#include <iostream>
#include <string>

class Anything
{
    int m_value;
public:
    Anything() { m_value = 0; }
    void add( int value ) { m_value += value; }
    int getValue() { return m_value; }

    friend void reset( Anything & anything ); // declaration
};

// initialization friend function
void reset(Anything & anything )
{
    anything.m_value = 0;
}


int main()
{
    Anything one;
    one.add(7);
    std::cout << one.getValue() << '\n';
    reset(one); // using friend function
    std::cout << one.getValue() << '\n';

}
