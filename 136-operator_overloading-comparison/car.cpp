#include <iostream>
#include <string>
#include "car.h"

Car::Car(const std::string & company, const std::string & model) 
  : m_company(company), m_model(model) {}

bool operator==(const Car & c1, const Car & c2)
{
  return c1.m_company == c2.m_company && c1.m_model == c2.m_model;
}
bool operator!=(const Car & c1, const Car & c2)
{
  return !(c1 == c2);
}

std::ostream& operator<<(std::ostream & out, const Car &car)
{
  out << "Car company: " << car.m_company << ", model: " << car.m_model;
  return out;
}

bool operator<(const Car & c1, const Car & c2)
{
  return (c1.m_company < c2.m_company || ( c1.m_company == c2.m_company && c1.m_model < c2.m_model));
}







