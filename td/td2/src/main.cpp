#include <iostream>
#include "../include/vector.h"

int main(void)
{
    Vector<int> intVector;
    for(int i=0; i<6; i++)
    {
        intVector.PushBack(i);
        std::cout << intVector[i] << std::endl;
    }
    try{
    std::cout << intVector[12] << std::endl;
    }
    catch(const char* expr)
    {
        std::cout << "Error: " << expr << std::endl;
    }

    return 0;
}