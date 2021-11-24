#include <iostream>
#include "numbers.h"

int main()
{

  Numbers num(7);

  std::cout << ++num;
  std::cout << ++num;
  std::cout << --num;
  std::cout << num++;
  std::cout << num++;
  std::cout << num--;


  return 0;
}



