#include "dollars.h"

Dollars::Dollars( int dollars ) : m_dollars(dollars) {}

Dollars Dollars::operator-() const
{
  return Dollars(-m_dollars);
}

int Dollars::getDollars() const { return m_dollars; }

Dollars operator+(const Dollars & d1, const Dollars & d2)
{
  return Dollars(d1.getDollars() + d2.getDollars());
}


