// simple static method use
#include <iostream>
#include <string>

class IdGenerator {
  static int s_id;
public:
  static int getValue();
};

int IdGenerator::s_id = 1; // initialization

int IdGenerator::getValue() { return s_id++; } // static method initialization

int main() {
  for ( int i = 0; i < 4; ++i )
    std::cout << IdGenerator::getValue() << '\n';

  return EXIT_SUCCESS;
}
