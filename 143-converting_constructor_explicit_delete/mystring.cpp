// using explicit word to prevent type convertion
// using delete word
#include <iostream>
#include <string>

class MyString
{
  std::string m_string;
  // put ctor to private
  // another way to prevent use of ctor
  MyString(double) {}
public:
  MyString(const char* string) : m_string(string)
  {
    std::cout << "Char ctor used!\n";
  }
  MyString(char) = delete; // prevent using char initialization
  explicit MyString(int value)
  { 
    std::cout << "Int ctor used!\n";
    m_string.resize(value);
  }
  friend std::ostream& operator<<(std::ostream&, const MyString&);
};

std::ostream& operator<<(std::ostream& out, const MyString& str)
{
  out << str.m_string;
  return out;
}

int main()
{
  // Wrong compilator convertion to int and using int ctor, but expects char*
  //MyString s1 = 'a'; // comp error
  MyString s1 = "Hello, world!"; // correct
  std::cout << s1;
  //MyString s2 = static_cast<MyString>('a'); // error due delete with char ctor
  MyString s2 = "Bye!";
  std::cout << s2;

  return 0;
}
