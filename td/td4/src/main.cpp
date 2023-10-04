#include "../include/vector.h"
#include "../include/smart_vector.h"
#include "../include/deque.h"
// Joker : slice.h
// Joker : vector_iteraor.h
#include <iostream>

int main(void)
{
    Vector<float> floatVector(3,1.5);
    Vector<std::string> stringVector(5, "Super chaine");
    Vector<char> charVector(3, 'a');

    std::cout << floatVector << "\n" << stringVector << "\n" << charVector << std::endl;
    return 0;
}