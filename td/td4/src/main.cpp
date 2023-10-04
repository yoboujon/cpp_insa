#include "../include/vector.h"
#include "../include/smart_vector.h"
#include "../include/deque.h"
// Joker : slice.h
// Joker : vector_iteraor.h
#include <iostream>

int main(void)
{
    Smart_Vector<int> smartInt, test(10,6);
    for(int i=0; i<6; i++)
        smartInt.PushBack(i);

    std::cout << smartInt << std::endl;
    std::cout << test << std::endl; 

    std::cout << smartInt + test << std::endl;
    std::cout << smartInt + smartInt << std::endl;

    Smart_Vector<int> little(5,1), big(10,5);
    little += big;
    std::cout << little << std::endl;
    little = Smart_Vector<int>(5,1);
    big += little;
    std::cout << big << std::endl;

    // Deque test
    Deque<int> dequeInt;
    for(int i=0; i<6; i++)
        dequeInt.PushBack(i);
    std::cout << "Deque push back: " << dequeInt << std::endl;
    for(int i=1; i<=6; i++)
        dequeInt.PushFront(i*10);
    std::cout << "Deque push front: " << dequeInt << std::endl;
    std::cout << "End capacity: " << dequeInt.Capacity() << std::endl;

    std::cout << "Deque Front Elements: " << dequeInt.GetFront() << std::endl;
    std::cout << "Deque Back Elements: " << dequeInt.GetBack() << std::endl;
    dequeInt.RemoveBack();
    std::cout << "After Removing Back: " << dequeInt << std::endl;
    dequeInt.PushBack(56);
    std::cout << "Pushing Back again: " << dequeInt << std::endl;
    dequeInt.RemoveFront();
    std::cout << "After Removing Front: " << dequeInt << std::endl;
    dequeInt.PushFront(10);
    std::cout << "Front: " << dequeInt.GetFront() << "\tBack: " << dequeInt.GetBack() << "\tFull Deque: " << dequeInt << "\tWith Capacity: " << dequeInt.Capacity() << std::endl;
    dequeInt.ShrinkToFit();
    std::cout << "After ShrinkToFit: " << dequeInt.Capacity() << "\tWith: " << dequeInt << std::endl;
    return 0;
}