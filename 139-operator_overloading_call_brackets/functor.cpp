// example of fucntor - function-like class
#include <iostream>

class Accumulator
{
  int m_counter;
public:
  Accumulator(int counter = 0) : m_counter(counter) {}
  int& operator() (int i) { return m_counter += i; }
};

int main()
{
  Accumulator a;
  std::cout << a(10) << '\n';
  std::cout << a(30) << '\n';

  return 0;
}
