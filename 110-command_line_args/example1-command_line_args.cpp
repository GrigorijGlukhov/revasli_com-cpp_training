// read arguments
// all arguments as string
#include <iostream>

int main( int argc, char *argv[] ) {
  
  for ( int arg = 0; arg < argc; ++arg )
    std::cout << arg << " - " << argv[arg] << '\n';

  return EXIT_SUCCESS;
}
