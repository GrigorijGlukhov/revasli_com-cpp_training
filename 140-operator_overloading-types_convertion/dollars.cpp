// overload type conversion
#include <iostream>

class Dollars
{
  int m_dollars;
public:
  Dollars(int dollars = 0) : m_dollars(dollars) {}
  int getDollars() { return m_dollars; }
  void setDollars(int dollars) { m_dollars = dollars; }
  operator int() { return m_dollars; }
};

class Cents
{
  int m_cents;
public:
  Cents( int cents = 0 ) : m_cents(cents) {}
  operator Dollars() { return m_cents / 100; }
};

void print(int value )
{
  std::cout << value;
}

int main()
{
  Dollars d(10);
  //print(d.getDollars()); // old-style printing with gette // old-style printing with getterr
  print(d); // overloaded type convertion use
  Cents cents(700);

  std::cout << '\n';
  Dollars d2 = static_cast<Dollars>(cents);
  print(d2);

  return 0;
}
