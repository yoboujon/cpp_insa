#ifndef HEADER_POLYGONE
#define HEADER_POLYGONE

#include "figure.h"
#include <sys/types.h>

class Polygone : public Figure {
public:
    Polygone(u_int64_t nb_cotes);
    virtual std::string afficherCaracteristiques() override;
    virtual int perimetre() override;

protected:
    u_int64_t _nbcotes;
};

class Rectangle : public Polygone {
public:
    Rectangle(uint hauteur, uint longueur);
    virtual std::string afficherCaracteristiques() override;
    virtual int perimetre() override;

protected:
    uint _hauteur, _longueur;
};

class Carre : public Rectangle {
public:
    Carre(uint cote);
};

class TriangleEquilateral : public Polygone
{
public:
    TriangleEquilateral(uint cote);
    virtual std::string afficherCaracteristiques() override;
    virtual int perimetre() override;
private:
    uint _cote;
    float _angle;
};

#endif // HEADER_POLYGONE