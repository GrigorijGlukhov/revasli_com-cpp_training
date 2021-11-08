// factorial
//
#include <iostream>

int factorial( int value ) {
  if ( value < 1 )
    return 1;
  else
    return factorial( value - 1 ) * value;
}

int main() {

  // list of factorials
  for ( int number = 1; number < 10; ++number )
    std::cout << "result: " << factorial(number) << '\n';

  return EXIT_SUCCESS;
}
