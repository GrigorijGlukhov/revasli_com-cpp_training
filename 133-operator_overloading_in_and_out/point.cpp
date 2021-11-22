#include <iostream>
#include "point.h"

Point::Point()
{
  m_x = 0.0;
  m_y = 0.0;
  m_z = 0.0;
}

Point::Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z) {}

std::ostream& operator<< (std::ostream &out, const Point &point)
{
  out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
  return out;
}

std::istream& operator>> (std::istream &in, Point &point)
{
  in >> point.m_x;
  in >> point.m_y;
  in >> point.m_z;

  return in;
}
