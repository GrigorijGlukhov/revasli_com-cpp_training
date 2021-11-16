// using friend function

#include <iostream>
#include <string>

class Something {
    int m_value;
public:
    Something( int value ) : m_value(value) {}
    friend bool isEqual(Something & some1, Something & some2);
};

bool isEqual(Something & some1, Something & some2)
{
    return some1.m_value == some2.m_value;
}

int main()
{
    Something sm1(10);
    Something sm2(20);
    std::cout << isEqual(sm1, sm2) << '\n';

    return EXIT_SUCCESS;
}

