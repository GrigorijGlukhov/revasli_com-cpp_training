// class Matrix
// example of using () operator overloading
#include <iostream>
#include <cassert>

class Matrix
{
  double m_data[5][5];
public:
  Matrix()
  {
    for(int row = 0; row < 5; ++row)
      for(int col = 0; col < 5; ++col)
        m_data[row][col] = 0.0;
  }
  double& operator()(int row, int col) // using () overloading
  {
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);
    return m_data[row][col];
  }
  void operator()() // usign () overloading without parameters
  {
    for(int row = 0; row < 5; ++row)
      for(int col = 0; col < 5; ++col)
        m_data[row][col] = 0.0;
  }
};

int main()
{
  Matrix m;
  m(2, 3) = 3.6;
  m();
  std::cout << m(2, 3);

  return 0;
}
