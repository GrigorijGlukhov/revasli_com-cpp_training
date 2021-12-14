// constructors and initialization in children classes
//
#include <iostream>
#include <string>

class Human
{
  std::string m_name;
  int m_age;
public:
  Human(std::string name = "", int age = 0) : m_name(name), m_age(age) {}
  std::string getName() const { return m_name; }
};

class BasketballPlayer : public Human
{
  double m_gameAverage;
  int m_points;
public:
  BasketballPlayer(std::string name = "", int age = 0, double gameAverage = 0.0, int points = 0) 
    : Human(name, age), m_gameAverage(gameAverage), m_points(points) {}
  double getAverage() { return m_gameAverage; }
};


int main()
{
  BasketballPlayer("Alex", 34, 35.6, 300);

  return 0;
}
