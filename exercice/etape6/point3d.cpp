#include "point3d.h"

Point3D::Point3D()
    : Point2D()
    , _z(0.0f)
{
}

Point3D::Point3D(float x, float y, float z)
    : Point2D(x, y)
    , _z(z)
{
}

Point3D::Point3D(Point2D point, float z)
    : Point2D(point)
    , _z(z)
{
}

Point3D::~Point3D()
{
}

void Point3D::Saisie(float x, float y, float z)
{
    Point2D::Saisie(x, y);
    _z = z;
}

void Point3D::Affiche()
{
    std::cout << "[POINT] X= " << _x << "\tY=" << _y << "\tZ= " << _z << std::endl;
}

Point3D Point3D::operator+(const Point3D& other)
{
    return { this->_x + other._x, this->_y + other._y, this->_z + other._z };
}

Point3D Point3D::operator+(const Point2D& other)
{
    Point3D returnOther(other,0.0f);
    return { this->_x + returnOther._x, this->_y + returnOther._y, this->_z + returnOther._z };
}

/*
Point3D operator+(const Point2D& point2d, const Point3D& point3d)
{
    Point3D returnOther(point2d,0.0f);
    return { point3d._x + returnOther._x, point3d._y + returnOther._y, point3d._z + returnOther._z };
}
*/

Point3D operator*(int value, const Point3D& point)
{
    return { point._x*value, point._y*value , point._z*value };
}

// Dans les deux sens, un second operator* doit être crée.
Point3D operator*(const Point3D& point, int value)
{
    return (value*point);
}
