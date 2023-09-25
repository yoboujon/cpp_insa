#include "../include/vector.h"
#include <iostream>

Vector::Vector()
    : _value(1)
{}

Vector::~Vector()
{}

void Vector::Affiche()
{
    std::cout << "Vector: " << _value << std::endl;
}