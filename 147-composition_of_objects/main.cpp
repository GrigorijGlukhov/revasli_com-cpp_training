// Composition class example
#include "creature.hpp"

int main()
{
  // Creature creation
  std::cout << '\n';
  std::cout << "Enter your creature name: ";
  std::string name;
  std::cin >> name;
  Creature creature(name, Point2D(5, 6)); // Using composition in class Point2D and Creature

  while(1)
  {
    // Print crature name and its location
    std::cout << creature << '\n';

    std::cout << "Enter new creature location X(-1 to exit): ";
    int x = 0;
    std::cin >> x;
    if ( x == -1 )
      break;

    std::cout << "Enter new creature location Y(-1 to exit): ";
    int y = 0;
    std::cin >> y;
    if ( y == -1 )
      break;

    creature.moveTo(x, y);
  }

  return 0;
}
