#include <iostream>
#include "fraction.h"

Fraction::Fraction( int numerator = 1, int denominator = 1 ) : m_num(numerator), m_den(denominator) 
{
  reduce(); // using reduce method inside ctor, bacause we recreate anonimous objects
}
Fraction::Fraction()
{
  m_num = 0; m_den = 0;
}
void Fraction::print()
{
  std::cout << m_num << '/' << m_den << '\n';
}
int Fraction::nod(int a, int b) // get nod value
{
  return (b == 0) ? ( a > 0 ? a : -a ) : nod(b, a % b);
}
void Fraction::reduce() // reduce fraction by nod 2/4 -> 1/2
{
  int _nod = nod(m_num, m_den);
  m_num /= _nod;
  m_den /= _nod;
}

Fraction operator*(const Fraction & f1, const Fraction & f2)
{
  return Fraction(f1.m_num*f2.m_num, f1.m_den*f2.m_den);
}
Fraction operator*(const Fraction & f1, int value)
{
  return Fraction(f1.m_num*value, f1.m_den);
}
Fraction operator*(int value, const Fraction & f1)
{
  return f1 * value;
}

std::ostream& operator<<(std::ostream& out, const Fraction &f)
{
  out << f.m_num << '/' << f.m_den;
  return out;
}

std::istream& operator>>(std::istream& in, Fraction &f)
{
  in >> f.m_num;
  in >> f.m_den;
  return in;
}


