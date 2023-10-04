#ifndef HEADER_SMART_VECTOR
#define HEADER_SMART_VECTOR

#include "vector.h"
#include <algorithm>

template <class T>
class Smart_Vector : public Vector<T> {
public:
    Smart_Vector() : Vector<T>() {};
    Smart_Vector(size_t capacity): Vector<T>(capacity) {};
    Smart_Vector(size_t capacity, T value): Vector<T>(capacity,value) {};
    Smart_Vector(const Vector<T>& other) : Vector<T>(other) {};
    Smart_Vector<T> operator+(const Smart_Vector<T>& other);
    Smart_Vector<T>& operator+=(const Smart_Vector<T>& other);
};

template <class T>
Smart_Vector<T> Smart_Vector<T>::operator+(const Smart_Vector<T>& other)
{
    // Gathering the vector with the greater size.
    auto& maxVector = (this->_size > other._size ? *this : other);
    Smart_Vector<T> returnVector(maxVector._size);
    returnVector._size = returnVector._capacity;
    size_t i(0);

    // Adding both vectors from 0 to the minimum size
    for(i=0; i<std::min(this->_size,other._size); i++)
        returnVector._values[i] = this->_values[i] + other._values[i];
    // Then simply copying the max vector values onto the return vector.
    for(size_t j=i; j<returnVector._size; j++)
        returnVector._values[j] = maxVector._values[j];
    return returnVector;
}

template <class T>
Smart_Vector<T>& Smart_Vector<T>::operator+=(const Smart_Vector<T>& other)
{
    size_t i(0), minimumSize(std::min(this->_size,other._size));
    for(i = 0; i<minimumSize ; i++)
        this->_values[i] += other._values[i];
    for(size_t j=i; j<other._size ; j++)
        this->PushBack(other._values[j]);
    return *this;
}

#endif // HEADER_SMART_VECTOR