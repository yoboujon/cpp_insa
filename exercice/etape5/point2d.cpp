#include "point2d.h"
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

void Point2D::Affiche2()
{
    Affiche();
}

Point2D Point2D::operator+(const Point2D& other)
{
    return { this->_x + other._x, this->_y + other._y };
}

Point2D operator*(int value, const Point2D& point)
{
    return {point._x*value, point._y*value};
}
