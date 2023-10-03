#include "../include/vector.h"
#include "../include/smart_vector.h"
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
    return 0;
}