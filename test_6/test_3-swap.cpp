#include <iostream>

void swap( int & a, int & b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {

  int a = 10, b = 20;
  swap(a, b);
  std::cout << "\nResult of swap: a = " << a << " b = " << b << '\n';

  return EXIT_SUCCESS;
}
