#include <cassert>
#include "intarray.h"

int& IntArray::operator[] (int index)
{
  assert(index >= 0 && index < 10);
  return m_array[index];
}

const int& IntArray::operator[] (int index) const
{
  return m_array[index];
}




