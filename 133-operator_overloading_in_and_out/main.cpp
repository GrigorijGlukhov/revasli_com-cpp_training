// << in and out operator overloading 
#include <iostream>
#include "point.h"
#include "fraction.h"

int main()
{
  Fraction f1;
  std::cout << "Enter first fraction: ";
  std::cin >> f1;

  Fraction f2;
  std::cout << "Enter second fraction: ";
  std::cin >> f2;

  std::cout << f1 << '*' << f2 << '=' << f1 * f2 << '\n';

  std::cout << "Enter a point: ";
  Point p1;
  std::cin >> p1;

  std::cout << "You entered: " << p1;

  std::cout << '\n';
  return 0;
}
