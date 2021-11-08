// simple recursion example
// calc sum between 1 and n
//
#include <iostream>

int recSun( int value ) {
  if ( value <= 0 ) // exit because less than 1
    return 0;
 if ( value == 1 ) // nothing to calculate
    return 1;
 else
   return recSum( value - 1 ) + value;
}

int main() {

  recSum(4);
  
  return EXIT_SUCCESS;
}
