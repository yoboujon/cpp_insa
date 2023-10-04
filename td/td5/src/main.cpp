#include "../include/vector.h"
#include "../include/smart_vector.h"
#include "../include/deque.h"
// Joker : slice.h
// Joker : vector_iteraor.h
#include <iostream>

int main(void)
{
    Vector<float> floatVect(4,3.5f);
    std::cout << floatVect * 9.0f << std::endl;
    std::cout << 9.0f * floatVect << std::endl;
    return 0;
}