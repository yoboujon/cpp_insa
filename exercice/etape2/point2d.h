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
    private:
        float _x,_y;
};

#endif