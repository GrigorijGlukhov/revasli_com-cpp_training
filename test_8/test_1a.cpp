#include <iostream>
#include <string>

class Point
{
    double m_a;
    double m_b;
public:
    Point(double a = 0.0, double b = 0.0) : m_a(a), m_b(b) {}
    void print()
    {
        std::cout << "Point(" << m_a << ',' << m_b << ")\n";
    }
};

int main()
{

    Point p1;
    Point p2(2, 5);

    p1.print();
    p2.print();

    return 0;
}
