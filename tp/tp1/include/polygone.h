#ifndef HEADER_POLYGONE
#define HEADER_POLYGONE

#include <sys/types.h>

#include "figure.h"
#include "coloriable.h"

class Polygone : public Figure {
public:
    Polygone(u_int64_t nb_cotes);
    ~Polygone();
    virtual std::string afficherCaracteristiques() override;
    virtual float perimetre() override;
    static uint getPolyCount() { return _polycount; };

protected:
    u_int64_t _nbcotes;
private:
    static uint _polycount;
};

class Rectangle : public Polygone {
public:
    Rectangle(uint hauteur, uint longueur);
    virtual std::string afficherCaracteristiques() override;
    virtual float perimetre() override;

protected:
    uint _hauteur, _longueur;
};

class Carre : public Rectangle {
public:
    Carre(uint cote);
};

class TriangleEquilateral : public Polygone {
public:
    TriangleEquilateral(uint cote);
    virtual std::string afficherCaracteristiques() override;
    virtual float perimetre() override;

private:
    uint _cote;
    float _angle;
};

class Cercle : public Polygone, public Coloriable {
public:
    Cercle(uint rayon, const std::string& couleur);
    virtual std::string afficherCaracteristiques() override;
    virtual float perimetre() override;
    uint getRayon();
    void setRayon(uint rayon);

private:
    uint _rayon;
};

#endif // HEADER_POLYGONE