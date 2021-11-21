// min max value select
// using friend function for operator overloading with different operators
#include <iostream>
#include <string>

class Values
{
  int m_min;
  int m_max;
public:
  Values(int min=0, int max=0) : m_min(min), m_max(max) {}
  int getMin() { return m_min; }
  int getMax() { return m_max; }
  friend Values operator+(const Values &, const Values &);
  friend Values operator+(const Values &, int);
  friend Values operator+(int, const Values &);
};
Values operator+(const Values &v1, const Values &v2)
{
  int min = v1.m_min < v2.m_min ? v1.m_min : v2.m_min;
  int max = v1.m_max > v2.m_max ? v1.m_max : v2.m_max;
  return Values(min, max);
}
Values operator+(const Values &v1, int value)
{
  int min = v1.m_min < value ? v1.m_min : value;
  int max = v1.m_max > value ? v1.m_max : value;
  return Values(min, max);
}
Values operator+(int value, const Values & v1)
{
  return v1 + value; // here using operator+(const Values & v1, int value)
}

int main()
{
  Values v1(1, 10);
  Values v2(11, 20);
  Values v3(7, 10);
  
  Values v4 = v1 + v2 + 10 + 11 + v3 + 2;

  std::cout << "Result: min: " << v4.getMin() << " max: " << v4.getMax();



  return 0;
}
