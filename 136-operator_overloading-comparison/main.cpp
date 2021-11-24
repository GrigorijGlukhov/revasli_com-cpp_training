#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "car.h"


int main()
{

  Car car1("Forn", "Mustang");
  Car car2("Renault", "Logan");

  if(car1 == car2)
    std::cout << "Car 1 is equal to car 2!\n";
  else
    std::cout << "Car 1 isn't equal to car 2!\n";

  std::vector <Car> cars;
  cars.push_back(Car("Ford", "Mustrang"));
  cars.push_back(Car("Renault", "Logan"));
  cars.push_back(Car("Ford", "Ranger"));
  cars.push_back(Car("Renault", "Duster"));

  std::sort(cars.begin(), cars.end());
  
  for ( auto & car : cars )
    std::cout << car << '\n';
  
  return 0;
}



