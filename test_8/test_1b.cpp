#include <iostream>
#include <string>
#include <cmath>

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
    double distanceTo(const Point & p)
    {
        return sqrt((m_a - p.m_a) * (m_a - p.m_a) + (m_b - p.m_b) * (m_b - p.m_b));
    }
};

int main()
{

    Point p1;
    Point p2(2, 5);

    p1.print();
    p2.print();
    
    std::cout << "Distace is: " << p1.distanceTo(p2) << "\n";

    return 0;
}

