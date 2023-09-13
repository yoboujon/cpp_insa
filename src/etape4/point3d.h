#ifndef HEADER_POINT3D
#define HEADER_POINT3D

#include "point2d.h"

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
        Point3D operator*(int left);
    private:
        float _z;
};

#endif