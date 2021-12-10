#include <iostream>

#include "arrayint.h"

int main()
{
  ArrayInt a(10);
  a[5] = 35;
  std::cout << a.getLength() << " and value of index 5 is " << a[5] << '\n';

  a.reallocate(100);
  std::cout << a.getLength() << " and value of index 5 is " << a[5] << '\n';
  a.resize(10);
  std::cout << a.getLength() << " and value of index 5 is " << a[5] << '\n';

  for( int i = 0; i < a.getLength(); ++i )
    a[i] = i+1; // by reference

  a.insertBefore(55, 3);
  a.remove(7);

  for( int i = 0; i < a.getLength(); ++i )
    std::cout << a[i] << ' ';

  return 0;
}
