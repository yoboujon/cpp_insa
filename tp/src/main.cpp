#include "../include/polygone.h"
#include <iostream>

int main(void)
{
    Polygone coolPoly(5);
    std::cout << coolPoly.afficherCaracteristiques() << std::endl;
    Rectangle rect(4,8);
    std::cout << rect.afficherCaracteristiques() << std::endl;
    Carre car(2);
    std::cout << car.afficherCaracteristiques() << std::endl;
}