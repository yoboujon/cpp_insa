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

int main(void)
{
    Point2D pointA(2.0f,3.0f);
    Point2D pointB(1.0f);
    Point2D pointC;
    pointA.Saisie(4.31f, 5.45f);

    pointA.Affiche();
    pointB.Affiche();
    pointC.Affiche();
    return 0;
}