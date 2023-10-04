#ifndef HEADER_DEQUE
#define HEADER_DEQUE

#include "vector.h"
#include <algorithm>
#include <iostream>

template <class T>
class Deque : public Vector<T> {
public:
    Deque() : Vector<T>(), _frontIndex(-1) {};
    Deque(size_t capacity): Vector<T>(capacity), _frontIndex(-1) {};
    Deque(size_t capacity, T value): Vector<T>(capacity,value), _frontIndex(-1) {};
    Deque(const Vector<T>& other) : Vector<T>(other), _frontIndex(-1) {};
    void PushFront(T value);
    Deque<T> GetFront(void);
    Deque<T> GetBack(void);
    void RemoveFront(void);
    void RemoveBack(void);
    void ShrinkToFit(void);
private:
    int64_t _frontIndex;
};

template <class T>
void Deque<T>::PushFront(T value)
{
    // if the next size will overload the heap
    // We create a new allocation, and shift each data
    if (this->_capacity < this->_size + 1) {
        auto oldPtr = this->_values;
        this->_values = new T[this->_size * 2];
        this->_capacity *= 2;
        for (size_t i = 0; i < this->_size; i++)
            this->_values[i+1] = oldPtr[i];
        delete[] oldPtr;
    }
    // Else we only shift the data
    else{
        // _values[0] will be overwritten, so it serves as a temporary value
        // To store the overwritten index
        auto tempActual(this->_values[0]);
        for(size_t i=0; i< this->_size ; i++)
        {
            this->_values[0] = this->_values[i+1];
            this->_values[i+1] = tempActual;
            tempActual = this->_values[0];
        }
    }
    this->_values[0] = value;
    this->_size++;
    _frontIndex++;
}

template <class T>
Deque<T> Deque<T>::GetFront(void)
{
    if(this->_frontIndex == -1)
        throw "This Deque doesn't have front elements";
    Deque<T> returnDeque(this->_frontIndex+1);
    returnDeque._size = this->_frontIndex+1;
    for(int64_t i=0; i< this->_frontIndex+1 ; i++)
        returnDeque._values[i] = this->_values[i];
    return returnDeque;
}

template <class T>
Deque<T> Deque<T>::GetBack(void)
{
    Deque<T> returnDeque(this->_size-(this->_frontIndex+1));
    returnDeque._size = this->_size-(this->_frontIndex+1);
    for(size_t i = this->_frontIndex+1, j=0 ; i<this->_size ; i++, j++)
        returnDeque._values[j] = this->_values[i];
    return returnDeque;
}

template <class T>
void Deque<T>::RemoveFront(void)
{
    for(size_t i = this->_frontIndex+1, j=0 ; i<this->_size ; i++, j++)
        this->_values[j] = this->_values[i];
    this->_size -= (this->_frontIndex+1);
    this->_frontIndex = -1;
}

// The Capacity is not shrunk during this process.
template <class T>
void Deque<T>::RemoveBack(void)
{
    this->_size = this->_frontIndex+1;
}

template <class T>
void Deque<T>::ShrinkToFit(void)
{
    auto oldPtr = this->_values;
    this->_values = new T[this->_size];
    for(size_t i=0; i<this->_size; i++)
        this->_values[i] = oldPtr[i];
    delete[] oldPtr;
    this->_capacity = this->_size;
}

#endif //HEADER_DEQUE