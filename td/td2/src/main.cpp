#include "../include/vector.h"
#include <iostream>

int main(void)
{
    Vector<int> intVector;
    for (int i = 0; i < 6; i++) {
        intVector.PushBack(i);
        std::cout << intVector[i] << std::endl;
    }

    try {
        std::cout << intVector[12] << std::endl;
    } catch (const char* expr) {
        std::cout << "Error: " << expr << std::endl;
    }
    intVector[2] = 21;
    std::cout << intVector << std::endl;

    Vector<int> secondVector(intVector.Size(), 5), tooLargeVector(3, 10);
    std::cout << secondVector + intVector << std::endl;
    try {
        std::cout << tooLargeVector + intVector << std::endl;
    } catch (const char* expr) {
        std::cout << "Error: " << expr << std::endl;
    }

    intVector+=secondVector;
    std::cout << intVector << std::endl;
    try {
        tooLargeVector += intVector;
    } catch (const char* expr) {
        std::cout << "Error: " << expr << std::endl;
    }
    return 0;
}