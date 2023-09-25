#include <iostream>
#include "../include/vector.h"

int main(void)
{
    Vector<int> intVector;
    for(int i=0; i<6; i++)
        intVector.PushBack(i);
    std::cout << "Integer vector: " << intVector << std::endl;

    Vector<float> floatVector(10,1.2);
    std::cout << "Float vector: " << floatVector << std::endl;

    Vector<char> charVector(5);
    std::cout << "Capacity of charVector:" << charVector.Capacity() << "\t Size of charVector: " << charVector.Size() << std::endl;
    std::cin >> charVector;
    std::cout << "char vector: " << charVector << std::endl;
    return 0;
}

// 1.2.1 : Les fonctions sont déclarées dans l'objet car elles sont amies. La définition de la fonction, elle, est en dehors de l'objet car elle a un accès aux valeurs privées via friend.
// Nous surchargeons l'opérateur std::cout/std::cin, donc la fonction n'est pas une modification de l'opérateur <</>> de Vector, mais de std::ostream/std::istream. 