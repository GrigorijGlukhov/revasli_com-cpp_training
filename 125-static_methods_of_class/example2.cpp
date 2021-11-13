// static member of class
// initialization of static member is hidden inside class

#include <iostream>
#include <string>
#include <vector>

class Something {
  static std::vector<char> s_myChars;
public:
  class _nested // define inner class _nested
  {
  public:
    _nested() // _nested ctor
    {
      s_myChars.push_back('e');
      s_myChars.push_back('i');
      s_myChars.push_back('d');
      s_myChars.push_back('o');
      s_myChars.push_back('s');
    }
  };
  // static method for print chars
  static void getElements() {
    for ( auto const elem : s_myChars )
      std::cout << elem << ' ';
  }
private:
  static _nested s_initializer; // static object of class _nested. run _nested ctor
};

std::vector<char> Something::s_myChars;
Something::_nested Something::s_initializer; // activate _nested creation via static object initializer

int main() 
{
  Something::getElements();
  return EXIT_SUCCESS;
}
