#ifndef HEADER_POINT2D
#define HEADER_POINT2D

#include <ostream>

class Point2D {
    public:
        Point2D();
        Point2D(float x);
        Point2D(float x, float y);
        ~Point2D();
        void Saisie(float x, float y);
        virtual void Affiche();
        virtual void Affiche2();
        Point2D operator+(const Point2D& other);
        friend std::ostream& operator<<(std::ostream& stream, const Point2D& point);
        friend std::istream& operator>>(std::istream& stream, Point2D& point);
        friend Point2D operator*(int value, const Point2D& point);
    protected:
        float _x,_y;
};

#endif