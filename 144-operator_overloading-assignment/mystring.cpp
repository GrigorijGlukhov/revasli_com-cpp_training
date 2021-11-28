// self-assignment
// protection against self-assignment
#include <iostream>

class MyString
{
  char *m_data;
  int m_length;
public:
  MyString(const char *data = "", int length = 0) : m_length(length)
  {
    if (!length)
      m_data = nullptr;
    else
      m_data = new char[m_length];

    for(int i = 0; i < length; ++i)
      m_data[i] = data[i];
  }
  MyString& operator=(const MyString &);
  friend std::ostream& operator<<(std::ostream&, const MyString &);
};

//MyString& MyString::operator=(const MyString &str)
//{
//  m_data = str.m_data;
//  m_length = str.m_length;
//  return *this;
//}

MyString& MyString::operator=(const MyString &str)
{
//  char  _temp[str.m_length];                // fix for selfassignmet
//  for ( int i = 0; i < str.m_length; ++i )  // prevent lost str.m_data pointer
//    _temp[i] = str.m_data[i];               // on delete[] m_data;
  
  // check for self-assignment
  if (this == &str)
    return *this;


  if(m_data) delete[] m_data;
  m_length = str.m_length;
  m_data = new char[m_length];
  for ( int i = 0; i < m_length; ++i )
    //m_data[i] = str.m_data[i];
    m_data[i] = str.m_data[i];
  //delete[] _temp;
  return *this;
}

std::ostream& operator<<(std::ostream &out, const MyString &str)
{
  out << str.m_data;
  return out;
}


int main()
{
  MyString str1("Alex", 4);
  MyString str2;
  str2 = str1;
  //std::cout << str2 << '\n';
  str2 = str2; // self-assignment is blocked
  std::cout << str2 << '\n';


  return 0;
}

