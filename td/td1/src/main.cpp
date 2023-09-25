#include <iostream>
#include "../include/vector.h"

int main(void)
{
    Vector<int> coolVector;
    std::cout << "Actual size:" << coolVector.Size() << "\tCapacity: " << coolVector.Capacity() << std::endl;
    coolVector.Display();
    coolVector.PushBack(123);
    coolVector.Display();
    std::cout << "Actual size:" << coolVector.Size() << "\tCapacity: " << coolVector.Capacity() << std::endl;
    coolVector.PushBack(124);
    coolVector.Display();
    std::cout << "Actual size:" << coolVector.Size() << "\tCapacity: " << coolVector.Capacity() << std::endl;
    coolVector.PushBack(125);
    coolVector.Display();
    std::cout << "Actual size:" << coolVector.Size() << "\tCapacity: " << coolVector.Capacity() << std::endl;
    coolVector.PushBack(126);
    coolVector.Display();
    std::cout << "Actual size:" << coolVector.Size() << "\tCapacity: " << coolVector.Capacity() << std::endl;

    Vector<float> anotherCoolVector(10,1.2);
    anotherCoolVector.Display();
    return 0;
}