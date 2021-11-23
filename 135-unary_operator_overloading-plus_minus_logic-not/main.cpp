#include <iostream>
#include "dollars.h"
#include "something.h"

int main()
{
  Dollars d1(10);
  Dollars d2 = -d1;

  std::cout << "You have: " << d2.getDollars() << " dollars.\n";

  Something sm1;
  if (!sm1)
    std::cout << "Something is null!\n";
  else
    std::cout << "Something isn't null!\n";

  Something sm2(10.0, 3.5, 1.2);
  std::cout << "Something is " << sm2 << '\n';
  sm2 = -sm2;
  std::cout << "Something is " << sm2 << '\n';
  sm2 = +sm2;
  std::cout << "Something is " << sm2 << '\n';


  return 0;
}
