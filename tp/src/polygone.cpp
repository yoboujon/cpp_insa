#include "../include/polygone.h"
#include "coloriable.h"

#include <cmath>
#include <sys/types.h>

#include <numbers>
#include <string>

uint Polygone::_polycount = 0;
Polygone::Polygone(u_int64_t nb_cotes)
    : _nbcotes(nb_cotes)
{
    _polycount++;
}

Polygone::~Polygone()
{
    _polycount--;
}

std::string Polygone::afficherCaracteristiques()
{
    return std::string("Nombre de cotes : " + std::to_string(_nbcotes));
}

float Polygone::perimetre() { return 0; }

Rectangle::Rectangle(uint hauteur, uint longueur)
    : Polygone(4)
    , _hauteur(hauteur)
    , _longueur(longueur)
{
}

std::string Rectangle::afficherCaracteristiques()
{
    return Polygone::afficherCaracteristiques() + std::string("\tPerimetre :" + std::to_string(perimetre()));
}

float Rectangle::perimetre() { return (2 * _longueur) + (2 * _hauteur); }

Carre::Carre(uint cote)
    : Rectangle(cote, cote)
{
}

TriangleEquilateral::TriangleEquilateral(uint cote)
    : Polygone(3)
    , _cote(cote)
    , _angle(60.0f)
{
}

std::string TriangleEquilateral::afficherCaracteristiques()
{
    return Polygone::afficherCaracteristiques() + std::string("\tPerimetre :" + std::to_string(perimetre()) + "\t Angles :" + std::to_string(_angle));
}

float TriangleEquilateral::perimetre() { return 3 * _cote; }

Cercle::Cercle(uint rayon, const std::string& couleur)
    : Polygone(INFINITY)
    , Coloriable(couleur)
    , _rayon(rayon)
{
}

std::string Cercle::afficherCaracteristiques()
{
    return std::string("Rayon: " + std::to_string(_rayon));
}

float Cercle::perimetre() { return 2 * std::numbers::pi * _rayon; }

uint Cercle::getRayon() { return _rayon; }

void Cercle::setRayon(uint rayon) { _rayon = rayon; }