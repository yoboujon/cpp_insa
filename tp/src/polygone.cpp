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