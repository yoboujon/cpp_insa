#include "../include/polygone.h"
#include <string>
#include <sys/types.h>

Polygone::Polygone(u_int64_t nb_cotes)
    : _nbcotes(nb_cotes)
{
}

std::string Polygone::afficherCaracteristiques()
{
    return std::string("Nombre de cotes : " + std::to_string(_nbcotes));
}

int Polygone::perimetre()
{
    return 0;
}

Rectangle::Rectangle(uint hauteur, uint longueur)
    : Polygone(4)
    , _hauteur(hauteur)
    , _longueur(longueur)
{
}

std::string Rectangle::afficherCaracteristiques()
{
    return Polygone::afficherCaracteristiques()+std::string("\tPerimetre :"+std::to_string(perimetre()));
}

int Rectangle::perimetre()
{
    return (2*_longueur)+(2*_hauteur);
}

Carre::Carre(uint cote)
    : Rectangle(cote, cote)
{
}

TriangleEquilateral::TriangleEquilateral(uint cote)
    : Polygone(3)
    , _cote(cote)
    , _angle(60.0f)
{}

std::string TriangleEquilateral::afficherCaracteristiques()
{
    return Polygone::afficherCaracteristiques()+std::string("\tPerimetre :"+std::to_string(perimetre())+"\t Angles :"+std::to_string(_angle));   
}

int TriangleEquilateral::perimetre()
{
    return 3*_cote;
}