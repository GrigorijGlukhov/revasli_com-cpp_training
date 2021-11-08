// convert number to binary
//
#include <iostream>

void toBinary( int value ) {
  if ( value == 0 )
    return;
  toBinary ( value / 2 );
  std::cout << value % 2 << " ";
}

int main() {

  toBinary(453);

  return EXIT_SUCCESS;
}
