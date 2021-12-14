// Basic inheritance example
//
#include <iostream>
#include <string>

class Human
{
public:
  std::string m_name;
  int m_age;
  Human( std::string name = "", int age = 0 ) : m_name(name), m_age(age)
  {}
  std::string getName() const { return m_name; }
  int getAge() { return m_age; }
};

class BasketballPlayer : public Human
{
public:
  double m_gameAverage;
  int m_points;
  BasketballPlayer( double gameAverage = 0.0, int points = 0 ) : m_gameAverage(gameAverage), m_points(points) {}
  double getGameAverege() { return m_gameAverage; }
  int getPoints() { return m_points; }
};

class Employee : public Human
{
public:
  int m_wage;
  long m_emoloyeeId;
  Employee( int wage = 0, long emoloyeeId = 0 ) : m_wage(wage), m_emoloyeeId(emoloyeeId) {}
  int getWage() const { return m_wage; }
  int getId() const { return m_emoloyeeId; }
};

class Supervisor : public Employee
{
public:
  int m_nOverseesIDs[5];
  Supervisor() {}
};


int main()
{
  Supervisor sv;

  return 0;
}
