#ifndef POINT_H
#define POINT_H

class Point
{
  double m_x, m_y, m_z;
public:
  Point();
  Point(double, double, double);
  // output ostream
  friend std::ostream& operator<< (std::ostream &, const Point &);
  // input istream
  friend std::istream& operator>> (std::istream &, Point &);
};

std::ostream& operator<< (std::ostream &, const Point &);
std::istream& operator>> (std::istream &, Point &);

#endif
