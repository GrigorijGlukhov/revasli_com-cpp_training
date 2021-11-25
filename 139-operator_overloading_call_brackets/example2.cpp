// class Matrix
// example of using () operator overloading
#include <iostream>
#include <string>
#include <cassert>

class MyString
{
  std::string m_string;
public:
  MyString(const std::string string="") : m_string(string) {}
  std::string operator() (int pos, int length) const
  {
    int _pos = m_string.size();
    if ( pos <= _pos )
      _pos = pos;
    return m_string.substr(_pos, length);
  }
  const char& operator[] (int index) const { return m_string[index]; }
  MyString operator+=(const std::string& str) { m_string += str; }
};

int main()
{
  MyString str("Hello, World!");
  std::cout << str(3,60) << " <\n";
  std::cout << str[3] << " <\n";
  str+=" Good bye!";
  std::cout << str(0, 30);

  return 0;
}
