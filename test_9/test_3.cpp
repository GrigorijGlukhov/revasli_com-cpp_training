// custom IntArray class with basic functionlity
// array creation ctor, copy ctor, operators <<. [], =
#include <iostream>
#include <cassert>

class IntArray
{
  int *m_array;
  int m_size;
public:
  IntArray(int size = 0) : m_size(size) 
  {
    assert(size && "Size of IntArray should be greater than zero!");
    m_array = new int[m_size];
  }
  ~IntArray() { delete[] m_array; }
  IntArray(const IntArray & i)
  {
    m_size = i.m_size;
    if (i.m_array)
    {
      m_array = new int[m_size];
      for(int index = 0; index < m_size; ++index)
        m_array[index] = i.m_array[index];
    }
    else
      m_array = 0;
  }
  friend std::ostream& operator<<(std::ostream&, const IntArray &);
  IntArray& operator=(const IntArray &);
  int& operator[] (const int);
};

std::ostream& operator<<(std::ostream & out, const IntArray & i)
{
  for (int index = 0; index < i.m_size; ++index)
    out << i.m_array[index];
  return out;
}

IntArray& IntArray::operator=(const IntArray & i)
{
  if (this == &i)
    return *this;
  m_size = i.m_size;
  delete[] m_array;
  m_array = new int[m_size];
  for(int index = 0; index < m_size; ++index)
    m_array[index] = i.m_array[index];
  return *this;
}

int& IntArray::operator[] (const int index)
{
  assert((index>=0) && (index <= m_size));
  return m_array[index];
}

IntArray fillArray()
{
  IntArray a(6);
  a[0] = 6;
  a[1] = 7;
  a[2] = 3;
  a[3] = 4;
  a[4] = 5;
  a[5] = 8;
  return a;
}

int main()
{
  IntArray a(10);
  IntArray b(100);
  a = b;
  std::cout << a << '\n';
  b[2] = 7;
  std::cout << b << '\n';
  IntArray c = fillArray();
  std::cout << c << '\n';

	return 0;
}
