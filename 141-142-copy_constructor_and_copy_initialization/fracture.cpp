// copy constructor 
// using copy constructor
// using(don't) copy initialization
#include <iostream>

class Fracture
{
  int m_numerator, m_denominator;
public:
  Fracture( int numerator = 0, int denominator = 1 ) 
    : m_numerator(numerator), m_denominator(denominator) 
  {
    std::cout << "Regular constructor worked!\n";
  }
  //copy constructor
  Fracture(const Fracture &f) : m_numerator(f.m_numerator), m_denominator(f.m_denominator)
  {
    std::cout << "Copy constructor worked!\n";
  }
  friend std::ostream& operator<<(std::ostream & out, const Fracture & f);
  int getNumerator() { return m_numerator; }
  void setNumerator(int value) { m_numerator = value; }
};

std::ostream& operator<<(std::ostream & out, const Fracture & f)
{
    out << f.m_numerator << '/' << f.m_denominator;
    return out;
}

// accept Fracture by value and return by value
Fracture makeNegative(Fracture f)
{
  f.setNumerator(-f.getNumerator());
  return f;
}

int main()
{
  Fracture f1(6, 7);
  Fracture f2(f1);
  std::cout << f2;
  std::cout << "\n-----------------------------------------------\n";
  // !!!here copy constructor will be used two times!!!
  //Copy constructor worked!
  //Copy constructor worked!
  std::cout << makeNegative(f1); // this function using copy ctor at arg and return

  return 0;
}
