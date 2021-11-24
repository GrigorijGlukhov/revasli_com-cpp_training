// operator overloading
// increment and decrement with prefix and postfix
// using dummy param for postfix operator overloading
#ifndef NUMBErS_H
#define NUMBERS_H

class Numbers
{
  int m_num;
public:
  Numbers(int);
  Numbers& operator++();
  Numbers& operator--();
  Numbers operator++(int);
  Numbers operator--(int);
  friend std::ostream& operator<<(std::ostream&, const Numbers &);
};

std::ostream& operator<<(std::ostream&, const Numbers &);

#endif
