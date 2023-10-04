#include "../include/matrice.h"
#include <iostream>

Matrice::Matrice()
{
    for(size_t i=0; i<MAX_MAT; i++)
        _vectors[i] = NULL;
}

Matrice::~Matrice()
{
    for(size_t i=0; i<MAX_MAT; i++)
        delete _vectors[i];
}

Vector<float>*& Matrice::operator[](const int indice)
{
    if((indice > 10) || (indice < 0))
        throw "A Matrix is composed of 10 arrays of vectors.";
    return _vectors[indice];
}

std::ostream& operator<<(std::ostream& stream,const Matrice& mat)
{
    for(size_t i=0; i<MAX_MAT; i++)
    {
        if(mat._vectors[i] != NULL)
            stream << "Mat[" << i << "]: {" << *(mat._vectors[i]) << "}\t";
    }
    return stream;
}