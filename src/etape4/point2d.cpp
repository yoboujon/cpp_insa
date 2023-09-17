#include "point2d.h"
#include "point3d.h"
#include <iostream>

Point2D::Point2D()
    : Point2D(0, 0)
{
}

Point2D::Point2D(float x)
    : Point2D(x, 0)
{
}

Point2D::Point2D(float x, float y)
    : _x(x)
    , _y(y)
{
}

Point2D::~Point2D()
{
}

void Point2D::Saisie(float x, float y)
{
    _x = x;
    _y = y;
}

void Point2D::Affiche()
{
    std::cout << "[POINT] X= " << _x << "\tY=" << _y << std::endl;
}

Point2D Point2D::operator+(const Point2D& other)
{
    return { this->_x + other._x, this->_y + other._y };
}

Point2D operator*(int value, const Point2D& point)
{
    return {point._x*value, point._y*value};
}

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

int main(void)
{
    Point2D pointA(2.0f, 3.0f);
    Point3D pointB(pointA, 4.0f), pointC(7.8f, 6.0f, 1.2f), pointD(1.0f,1.0f,1.0f);
    pointA.Affiche();
    pointB.Affiche();
    pointC.Affiche();
    pointC.Saisie(500.0f, 30.0f, 15.76f);
    pointC.Affiche();
    auto pointE = pointB+pointD;
    pointE.Affiche();
    (pointD*3).Affiche();
    std::cout << "Ajout d'un point2D (A, [2,3]) à un point3D (D, [1,1,1]) :" << std::endl;
    auto superPoint = pointD+pointA;
    superPoint.Affiche();
    return 0;
}