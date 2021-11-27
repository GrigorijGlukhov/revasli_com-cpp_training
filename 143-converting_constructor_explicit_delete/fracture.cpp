// conversion constructor 
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

  // compilator convert int to Fracture obj default ctor
  std::cout << makeNegative(7); 

  return 0;
}
