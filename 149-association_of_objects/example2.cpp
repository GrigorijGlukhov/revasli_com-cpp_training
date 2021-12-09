// aasociation without pointers
//
#include <iostream>
#include <string>

class Car
{
  std::string m_name;
  int m_id;
public:
  Car(std::string name, int id) : m_name(name), m_id(id) {}
  std::string getName() { return m_name; }
  int getId() { return m_id; }
};

class Carlot
{
  static Car m_cars[4];
public:
  Carlot() = delete; // prevent of object creation. This is static class
  static Car * getCar(int id)
  {
    for( int cnt = 0; cnt < 4; ++cnt )
      if( m_cars[cnt].getId() == id )
        return & (m_cars[cnt]);
    return nullptr;
  }
};

class Driver
{
  std::string m_name; // name of driver
  int m_id; // id of car driver own
public:
  Driver(std::string name, int id) : m_name(name), m_id(id) {}
  std::string getName() { return m_name; }
  int getCarId() { return m_id; }
};

Car Carlot::m_cars[4] = {Car("Camry", 5), Car("Focus", 14), Car("Vito", 73), Car("Levante", 58) };

int main()
{
  Driver d("Alex", 14);

  Car * car = Carlot::getCar(d.getCarId());

  if(car)
    std::cout << d.getName() << " has car " << car->getName() << '\n';
  else
    std::cout << d.getName() << " hasn't any car in this lot!\n";

  return 0;
}
