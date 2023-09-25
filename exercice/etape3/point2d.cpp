#include <iostream>
#include "point2d.h"

Point2D::Point2D()
    : Point2D(0,0)
{}

Point2D::Point2D(float x)
    : Point2D(x,0)
{}

Point2D::Point2D(float x, float y)
    : _x(x), _y(y)
{}

Point2D::~Point2D()
{}

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
    return {this->_x + other._x, this->_y + other._y};
}

// Question : Doit-t-on réellement ajouter friend pour pouvoir faire une opération dans les deux sens avec Point2D ?
Point2D operator*(int value, const Point2D& point)
{
    return {point._x*value, point._y*value};
}

int main(void)
{
    Point2D pointA(2.0f,3.0f);
    Point2D pointB(1.0f);
    Point2D pointC;
    pointA.Saisie(4.31f, 5.45f);

    pointA.Affiche();
    pointB.Affiche();
    pointC.Affiche();
    Point2D A(1,2), B(3,4),C;
    C = A + B;
    C.Affiche();
    C = 5*A;
    C.Affiche();
    return 0;
}