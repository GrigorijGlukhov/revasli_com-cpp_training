#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>

class Point2D
{
  int m_x;
  int m_y;
public:
  Point2D() : m_x(0), m_y(0) {}
  Point2D( int x, int y) : m_x(x), m_y(y) {}
  friend std::ostream& operator<<(std::ostream &, const Point2D &);
  void setPoint( int, int );
};

std::ostream& operator<<(std::ostream &, const Point2D &);

#endif // POINT2D_HPP

