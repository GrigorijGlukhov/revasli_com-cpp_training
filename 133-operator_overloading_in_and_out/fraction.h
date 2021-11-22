#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
  int m_num; // numerator
  int m_den; // denominator
public:
  Fraction(int, int);
  Fraction();
  void print();
  friend Fraction operator*(const Fraction &, const Fraction &);
  friend Fraction operator*(const Fraction &, int);
  friend Fraction operator*(int, const Fraction &);
  int nod(int, int); // get nod value
  void reduce(); // reduce fraction by nod 2/4 -> 1/2
  friend std::ostream& operator<<(std::ostream&, const Fraction &);
  friend std::istream& operator>>(std::istream&, Fraction &);
};

Fraction operator*(const Fraction &, const Fraction &);
Fraction operator*(const Fraction &, int);
Fraction operator*(int, const Fraction &);

std::ostream& operator<<(std::ostream&, const Fraction &);
std::istream& operator>>(std::istream&, Fraction &);

#endif
