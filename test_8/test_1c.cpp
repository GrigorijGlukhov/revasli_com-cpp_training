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
    friend double distanceFrom(const Point & p1, const Point & p2);
};

double distanceFrom(const Point & p1, const Point & p2)
{
    return sqrt((p1.m_a - p2.m_a) * (p1.m_a - p2.m_a) + (p1.m_b - p2.m_b) * (p1.m_b - p2.m_b));
}

int main()
{

    Point p1;
    Point p2(2, 5);

    p1.print();
    p2.print();
    
    std::cout << "Distace is: " << distanceFrom(p1, p2) << "\n";

    return 0;
}

