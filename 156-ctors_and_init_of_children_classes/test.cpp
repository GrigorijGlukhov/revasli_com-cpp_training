#include <iostream>
#include <string>

class Fruit
{
  std::string m_name;
  std::string m_color;
public:
  Fruit(std::string name = "", std::string color = "") : m_name(name), m_color(color) {}
  std::string getName() const { return m_name; }
  std::string getColor() const { return m_color; }
};

class Apple : public Fruit
{
  double m_fiber;
public:
  Apple(std::string name = "", std::string color = "", double fiber = 0.0) : Fruit(name, color), m_fiber(fiber) {}
  friend std::ostream & operator<< (std::ostream & out, const Apple & a)
  {
    out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.m_fiber << ')';
    return out;
  }
};

class Banana : public Fruit
{
public:
  Banana(std::string name = "", std::string color = "") : Fruit(name, color) {}
  friend std::ostream & operator<< (std::ostream & out, const Banana & b)
  {
    out << "Banana(" << b.getName() << ", " << b.getColor() << ')';
    return out;
  }
};

int main()
{
  Apple a("Red delicious", "red", 7.3);
  Banana b("Cavendish", "yellow");
  std::cout << a << '\n';
  std::cout << b << '\n';

  return 0;
}
