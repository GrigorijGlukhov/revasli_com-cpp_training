#include <iostream>
#include "numbers.h"

Numbers::Numbers(int num = 0) : m_num(num) {}

Numbers& Numbers::operator++()
{
  if(m_num == 8)
    m_num = 0;
  ++m_num;
  return *this;
}

Numbers& Numbers::operator--()
{
  if(m_num == 0)
    m_num = 8;
  --m_num;
  return *this;
}

Numbers Numbers::operator++(int) // using dummy int 
{
  Numbers temp(m_num);
  ++(*this);
  return temp;
}

Numbers Numbers::operator--(int) // using dummy int 
{
  Numbers temp(m_num);
  --(*this);
  return temp;
}

std::ostream& operator<<(std::ostream & out, const Numbers & num)
{
  out << num.m_num;
  return out;
}





