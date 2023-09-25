#ifndef HEADER_VECTOR
#define HEADER_VECTOR

#include <cstddef>

template<class T>
class Vector{
public:
    Vector();
    Vector(size_t capacity);
    Vector(size_t capacity, T value);
    ~Vector();
    void Display();
    size_t Size();
    size_t Capacity();
    void PushBack(T value);
private:
    T* _values;
    size_t _capacity;
    size_t _size;
};

#endif //HEADER_VECTOR