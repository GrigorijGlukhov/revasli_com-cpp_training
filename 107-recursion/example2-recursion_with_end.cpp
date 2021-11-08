// simple recursion example
#include <iostream>

void recursion( int count ) {
  std::cout << "push " << count << '\n';
  if ( count > 1 )
    recursion(count-1);
  std::cout << "pop " << count << '\n';
}

int main() {
  recursion(4);
  
  return EXIT_SUCCESS;
}
