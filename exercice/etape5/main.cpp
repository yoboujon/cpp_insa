#include "point2d.h"
#include "point3d.h"

int main(void)
{
    Point2D pointA(2.0f, 3.0f);
    Point3D pointB(pointA, 4.0f);
    pointB = pointB*5;
    pointA.Affiche2();
    pointB.Affiche2();
    return 0;
}