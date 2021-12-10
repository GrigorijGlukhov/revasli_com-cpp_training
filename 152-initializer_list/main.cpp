#include <iostream>

#include "arrayint.h"

int main()
{
  ArrayInt arr { 1, 3, 5, 7, 9, 12, 33 };
  for( int index = 0; index < arr.getLength(); ++index )
    std::cout << arr[index] << ' ';
  std::cout << '\n';
  arr = { 1, 3, 5, 7, 9, 12, 43, 6, 12, 55 };
  for( int index = 0; index < arr.getLength(); ++index )
    std::cout << arr[index] << ' ';

  return 0;
}
