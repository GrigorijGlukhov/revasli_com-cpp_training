#include <iostream>
#include "something.h"

Something::Something() { m_a = 0; m_b = 0; m_c = 0; }
Something::Something(double a = 0, double b = 0, double c = 0) : m_a(a), m_b(b), m_c(c) {}

Something Something::operator-() const
{
  return Something(-m_a, -m_b, -m_c);
}

Something Something::operator+() const
{
  double _a = m_a;
  double _b = m_b;
  double _c = m_c;
  if ( m_a < 0 ) 
    _a = -m_a;
  if ( m_b < 0 ) 
    _b = -m_b;
  if ( m_c < 0 ) 
    _c = -m_c;
  return Something(_a, _b, _c);
}

bool Something::operator!() const
{
  return ( m_a == 0 && m_b == 0 && m_c == 0 );
}

std::ostream& operator<<(std::ostream &out, const Something &s)
{
  out << s.m_a << ',' << s.m_b << ',' << s.m_c;
  return out;
}

