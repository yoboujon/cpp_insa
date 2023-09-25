#ifndef HEADER_POINT2D
#define HEADER_POINT2D

class Point2D {
    public:
        Point2D();
        Point2D(float x);
        Point2D(float x, float y);
        ~Point2D();
        void Saisie(float x, float y);
        void Affiche();
        Point2D operator+(const Point2D& other);
        friend Point2D operator*(int value, const Point2D& point);
    private:
        float _x,_y;
};

#endif