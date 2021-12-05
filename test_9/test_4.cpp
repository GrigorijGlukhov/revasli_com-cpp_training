// class that accepts two integers as frction number
#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath>

class FixedPoint
{
  int16_t m_base;
  int8_t  m_decimal;
 public:
  FixedPoint( int16_t base = 0, int8_t decimal = 0 )
    : m_base(base), m_decimal(decimal) 
  {
    // cut off if m_decimal > 99
    if (m_decimal < -99 || m_decimal > 99)
      m_decimal = m_decimal - (m_decimal%99);
    if(m_base != 0 && (m_base < 0 || m_decimal < 0))
    {
      if(m_decimal < 0)
        m_decimal = -m_decimal;
      if(m_base > 0)
        m_base = -m_base;
    }
  }
  // double ctor
  explicit FixedPoint(double value)
  {
    m_base = static_cast<int>(value);
    m_decimal = static_cast<int8_t>((value*100)-(m_base*100));
  }
  // << operator
  friend std::ostream& operator<<(std::ostream &, const FixedPoint &);
  // type convertion operator
  operator double() const
  {
    return m_base + static_cast<double>(m_decimal)/100;
  };
};

std::ostream& operator<<(std::ostream & out, const FixedPoint & f)
{
  //out << f.m_base + static_cast<double>(f.m_decimal)/100;
  out << static_cast<double>(f); // using convertion type operator
  return out;
}

int main()
{
  FixedPoint a(32, 58);
  std::cout << a << '\n';

  FixedPoint b(-3, 9);
  std::cout << b << '\n';

  FixedPoint c(4, -7);
  std::cout << c << '\n';

  FixedPoint d(-5, -7);
  std::cout << d << '\n';
  
  FixedPoint e(0, -3);
  std::cout << e << '\n';

  std::cout << static_cast<double>(e) << '\n';
  std::cout << "--------------------------------------------------\n";

  // using double ctor
  FixedPoint df(-7.5);
  std::cout << df << '\n';

  std::cout << "--------------------------------------------------\n";
  FixedPoint a1(0.03);
  std::cout << a1 << '\n';

  FixedPoint a2(-0.03);
  std::cout << a2 << '\n';

  FixedPoint a3(4.01);
  std::cout << a3 << '\n';

  FixedPoint a4(-4.01);
  std::cout << a4 << '\n';

  return 0;
}

