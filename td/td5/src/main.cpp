#include "../include/vector.h"
#include "../include/smart_vector.h"
#include "../include/deque.h"
#include "../include/matrice.h"

#include <iostream>

int main(void)
{
    Vector<float> floatVect(4,3.5f);
    std::cout << floatVect * 9.0f << std::endl;
    std::cout << 9.0f * floatVect << std::endl;

    Matrice mat;

    mat[0] = new Vector<float>(6,30.0f);
    //mat[1] = &floatVect;
    // This leads to pointer error when calling the ~Matrice() func.
    mat[2] = new Smart_Vector<float>(7, 20.0f);
    
    /*
    auto multipleVect = new Vector<float>[2];
    for(size_t i = 0; i< 2 ; i++)
        multipleVect[i].PushBack(1.9);
    mat[3] = multipleVect;
    */
    // This leads to an error because each Vector should not be an array but only a pointer.

    std::cout << mat << std::endl;
    return 0;
}