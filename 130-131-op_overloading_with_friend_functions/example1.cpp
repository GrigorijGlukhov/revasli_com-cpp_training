// using friend function for operator overloading
#include <iostream>
#include <string>

// original class
/*
class Dollars
{
  int m_dollars;
public:
  Dollars( int dollars ) : m_dollars(dollars) {}
  int getDollars() { return m_dollars; }
};
*/

class Dollars
{
  int m_dollars;
public:
  Dollars( int dollars ) : m_dollars(dollars) {}
  int getDollars() { return m_dollars; }
  friend Dollars operator+(const Dollars&, const Dollars&);
};

Dollars operator+(const Dollars & d1, const Dollars & d2)
{
  return Dollars(d1.m_dollars + d2.m_dollars);
}

int main()
{
  Dollars dol1(10);
  Dollars dol2(20);
  Dollars dol3(dol1+dol2);

  std::cout << "You have " << dol3.getDollars() << " dollars.";;

  return 0;
}
