#include <iostream>
#include "point3d.hpp"
#include "vector3d.hpp"

void Point3D::print()
{
    std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

void Point3D::moveByVector(const Vector3D &v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}
