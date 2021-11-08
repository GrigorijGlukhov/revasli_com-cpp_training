// sum all digits in value
//
#include <iostream>


int sumDigits( int value ) {
	if ( value < 10 )
		return value;
	return sumDigits( value / 10 ) + value % 10;
}

int main() {
	std::cout << sumDigits(482);

  return EXIT_SUCCESS;
}
