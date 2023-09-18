#ifndef HEADER_POINT3D
#define HEADER_POINT3D

#include "point2d.h"

#include <iostream>

class Point3D : public Point2D
{
    public:
        Point3D();
        Point3D(float x, float y, float z);
        Point3D(Point2D point,float z);
        ~Point3D();
        void Saisie(float x, float y, float z);
        void Affiche();
        // Bonus avec les operateurs.
        Point3D operator+(const Point3D& other);
        // Empêche une erreur lorsque point3D+point2D
        Point3D operator+(const Point2D& other);
        // Upgrade un point2D en point3D s'il est additioné avec ce dernier
        // Ne fonctionne pas à cause de problème d'overload...
        //friend Point3D operator+(const Point2D& point2d, const Point3D& point3d);
        friend Point3D operator*(int value, const Point3D& point);
        friend Point3D operator*(const Point3D& point, int value);
    private:
        float _z;
};

#endif