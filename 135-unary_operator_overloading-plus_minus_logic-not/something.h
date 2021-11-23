#ifndef SOMETHING_H
#define SOMETHINS_H

class Something
{
  double m_a, m_b, m_c;
public:
  Something();
  Something(double, double, double);
  Something operator-() const;
  Something operator+() const;
  bool operator!() const;
  friend std::ostream& operator<<(std::ostream &, const Something &);
};

std::ostream& operator<<(std::ostream &, const Something &);

#endif

