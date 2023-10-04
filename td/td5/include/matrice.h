#include "vector.h"

constexpr size_t MAX_MAT = 10;

class Matrice {
    public:
        Matrice();
        ~Matrice();
        Vector<float>*& operator[](const int indice);
        friend std::ostream& operator<<(std::ostream& stream, const Matrice& mat);
    private:
        Vector<float>* _vectors[MAX_MAT];
};