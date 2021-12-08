#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include "point2d.hpp"

class Creature
{
  std::string m_name;
  Point2D m_location;
public:
  Creature(const std::string & name, const Point2D & point)
    : m_name(name), m_location(point) {}
  friend std::ostream& operator<<(std::ostream &, const Creature &);
  void moveTo(const Point2D &);
  void moveTo(int, int);
};

std::ostream& operator<<(std::ostream &, const Creature &);

#endif // CREATURE_HPP
