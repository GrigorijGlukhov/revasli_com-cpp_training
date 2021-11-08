// simple recursion example
#include <iostream>

void recursion( int count ) {
  std::cout << "push" << count << '\n';
  recursion(count-1);
}

int main() {
  recursion(4);
  
  return EXIT_SUCCESS;
}
