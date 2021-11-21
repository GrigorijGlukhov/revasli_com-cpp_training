// operator overloading test
#include <iostream>
#include <string>

class Fraction
{
  int m_num; // numerator
  int m_den; // denominator
public:
  Fraction( int numerator = 1, int denominator = 1 ) : m_num(numerator), m_den(denominator) 
  {
    reduce(); // using reduce method inside ctor, bacause we recreate anonimous objects
  }
  void print()
  {
    std::cout << m_num << '/' << m_den << '\n';
  }
  friend Fraction operator*(const Fraction &, const Fraction &);
  friend Fraction operator*(const Fraction &, int);
  friend Fraction operator*(int, const Fraction &);
  int nod(int a, int b) // get nod value
  {
    return (b == 0) ? ( a > 0 ? a : -a ) : nod(b, a % b);
  }
  void reduce() // reduce fraction by nod 2/4 -> 1/2
  {
    int _nod = nod(m_num, m_den);
    m_num /= _nod;
    m_den /= _nod;
  }
};

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

int main()
{
  Fraction f1(3, 4);
  f1.print();

  Fraction f2(2, 7);
  f2.print();

  Fraction f3 = f1 * f2;
  f3.print();

  Fraction f4 = f1 * 3;
  f4.print();

  Fraction f5 = 5 * f2;
  f5.print();

  Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
  f6.print();

  return 0;
}
