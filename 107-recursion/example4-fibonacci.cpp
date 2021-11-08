// simple recursion example
// calc sum between 1 and n
//
#include <iostream>

int fibonacci( int value ) {
  if ( value <= 0 ) // exit because less than 1
    return 0;
 if ( value == 1 ) // nothing to calculate
    return 1;
 else
   return fibonacci(value - 1) + fibonacci(value - 2);
}

int main() {

  for ( int count = 0; count < 13; ++count )
    std::cout << fibonacci(count) << '\n';

  return EXIT_SUCCESS;
}
