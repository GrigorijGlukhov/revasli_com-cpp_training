#include "creature.hpp"

std::ostream& operator<<(std::ostream & out, const Creature & creature)
{
  out << "Creature name " << creature.m_name << " at location " << creature.m_location << ')';
  return out;
}
void Creature::moveTo(const Point2D & point)
{
  m_location = point;
}
void Creature::moveTo(int x, int y)
{
  m_location.setPoint(x, y);
}
