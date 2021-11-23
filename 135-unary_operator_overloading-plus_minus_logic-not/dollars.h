#ifndef DOLLARS_H
#define DOLLARS_H

class Dollars
{
  int m_dollars;
public:
  Dollars( int );
  Dollars operator-() const;
  int getDollars() const;
};

Dollars operator+(const Dollars &, const Dollars &);

#endif
