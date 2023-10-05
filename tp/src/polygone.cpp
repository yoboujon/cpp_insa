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
    return std::string("Nombre de cotes : 4\tPerimetre :"+std::to_string(perimetre()));
}

int Rectangle::perimetre()
{
    return _longueur * _hauteur;
}

Carre::Carre(uint cote)
    : Polygone(4)
    , _cote(cote)
{
}

std::string Carre::afficherCaracteristiques()
{
    return std::string("Nombre de cotes : 4\tPerimetre :"+std::to_string(perimetre()));
}

int Carre::perimetre()
{
    return _cote * _cote;
}