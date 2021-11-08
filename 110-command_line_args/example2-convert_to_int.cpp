// simple string arg convert routine with stringstream
// read arguments
// all arguments as string
#include <iostream>
#include <sstream> // for std::stringstream


int main( int argc, char *argv[] ) {

  std::stringstream convert(argv[1]); // create "convert" var

  int myInt;
  if (!(convert >> myInt)) // covert here
    myInt = 0; // if convert fail set default 0

  std::cout << "value is: " << myInt;

  return EXIT_SUCCESS;
}
