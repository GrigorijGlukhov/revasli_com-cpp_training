// class that accepts two integers as frction number
// part 2: overloading of ==, >>, -(unary) and +.
//
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
  friend std::istream& operator>>(std::istream &, FixedPoint &);
  // type convertion operator
  operator double() const
  {
    return m_base + static_cast<double>(m_decimal)/100;
  };
  friend bool operator==(const FixedPoint & f1, const FixedPoint & f2);
  FixedPoint operator-();
  FixedPoint& operator+(const FixedPoint &);
};

std::ostream& operator<<(std::ostream & out, const FixedPoint & f)
{
  //out << f.m_base + static_cast<double>(f.m_decimal)/100;
  out << static_cast<double>(f); // using convertion type operator
  return out;
}

std::istream& operator>>(std::istream & in, FixedPoint & d)
{
  double _in;
  in >> _in;
  d = FixedPoint(_in);
  return in;
}

bool operator==(const FixedPoint & f1, const FixedPoint & f2)
{
  return (f1.m_base == f2.m_base && f1.m_decimal == f2.m_decimal);
}

FixedPoint FixedPoint::operator-()
{
  return FixedPoint(-m_base, -m_decimal);
}

FixedPoint& FixedPoint::operator+(const FixedPoint &f)
{
  m_base += f.m_base;
  if(m_decimal + f.m_decimal > 99)
  {
    ++m_base;
    m_decimal = f.m_decimal-m_decimal;
  }
  m_decimal += f.m_decimal;
  return *this;
}

void SomeTest()
{
  std::cout << std::boolalpha;
  std::cout << (FixedPoint(0.75)  + FixedPoint(1.23)  == FixedPoint(1.98)  ) << '\n';   
  std::cout << (FixedPoint(0.75)  + FixedPoint(1.50)  == FixedPoint(2.25)  ) << '\n';   
  std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98) ) << '\n';
  std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25) ) << '\n';
  std::cout << (FixedPoint(0.75)  + FixedPoint(-1.23) == FixedPoint(-0.48) ) << '\n'; 
  std::cout << (FixedPoint(0.75)  + FixedPoint(-1.50) == FixedPoint(-0.75) ) << '\n'; 
  std::cout << (FixedPoint(-0.75) + FixedPoint(1.23)  == FixedPoint(0.48)  ) << '\n';  
  std::cout << (FixedPoint(-0.75) + FixedPoint(1.50)  == FixedPoint(0.75)  ) << '\n';  
}


int main()
{
  SomeTest();

  FixedPoint a(2.23);
  FixedPoint b(2, 23);

  std::cout << (a == b ? "true" : "false") << '\n';
  std::cout << a << ' ' << -a << ' ' << -b << '\n';
  std::cout << a + b << '\n';
  FixedPoint i;
  std::cin >> i;

  std::cout << '\n' << i << '\n';

  return 0;
}

