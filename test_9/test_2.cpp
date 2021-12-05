// test_9-2 Class Average that finds average value of entered sum
// 
#include <iostream>
#include <cstdint>

class Average
{
  std::int32_t  m_sum;
  std::int8_t   m_cnt;

  int calcAverage()
  {
    return static_cast<int>(m_sum/m_cnt);
  }
public:
  Average(std::int32_t val = 0, std::uint8_t cnt = 0) : m_sum(val), m_cnt(cnt) 
  {
    if ( val )
    {
      m_sum = val;
      ++m_cnt;
    }
  }
  friend std::ostream& operator<<(std::ostream&, Average&);
  Average& operator+=(int);
};

std::ostream& operator<<(std::ostream & out, Average & a)
{
  out << a.calcAverage();
  return out;
}

Average& Average::operator+=(int value)
{
  if ( !value )
    return *this;
  m_sum += value;
  ++m_cnt;
  return *this;
}


int main()
{
  Average avg;
  avg += 5;
  std::cout << avg << '\n';
  avg += 9;
  std::cout << avg << '\n';
  avg += 19;
  std::cout << avg << '\n';
  avg += -9;
  std::cout << avg << '\n';
  (avg += 7) += 11;
  std::cout << avg << '\n';

  Average copy = avg;
  std::cout << copy << '\n';



  return 0;
}
