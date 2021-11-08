#include <iostream>

// C-Style strings print
void printCStrings( const char * str ) {
  while( *str ) {
    std::cout << *str++;
  }
}

int main() {

  char str[] = "Hello, World!";
  int length = sizeof(str) / sizeof(str[0]);
  
  for ( int c = 0; c < length; ++c)
    std::cout << *(str+c);

  printCStrings("It works");

  return EXIT_SUCCESS;
}
