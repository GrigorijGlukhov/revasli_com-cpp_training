#include <iostream>
#include "dollars.h"

int main()
{
  Dollars d1(10);
  Dollars d2(20);
  Dollars dollarSum = d1 + d2;

  std::cout << "You have " << dollarSum.getDollars() << " dollars.";

  return 0;
}
