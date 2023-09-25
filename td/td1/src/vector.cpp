#include "../include/vector.h"
#include <cstddef>
#include <iostream>

template<class T>
Vector<T>::Vector() 
    : _capacity(1)
    , _size(0)
{
    _values = new T[1];
}

template<class T>
Vector<T>::Vector(size_t capacity) 
    : _capacity(capacity)
    , _size(0)
{
    _values = new T[capacity];
}

template<class T>
Vector<T>::Vector(size_t capacity, T value) 
    : _capacity(capacity)
    , _size(capacity)
{
    _values = new T[capacity];
    for(size_t i = 0; i<capacity; i++)
        _values[i] = value;
}


template<class T>
Vector<T>::~Vector()
{
    delete[] _values;
}

template<class T>
void Vector<T>::Display()
{
    for(size_t i = 0; i<_size; i++)
        std::cout << _values[i] << std::endl;
}

template<class T>
size_t Vector<T>::Capacity() { return _capacity; }
template<class T>
size_t Vector<T>::Size() { return _size; }

template<class T>
void Vector<T>::PushBack(T value)
{
    if (_capacity < _size+1)
    {
        T* oldPtr = _values;
        _values = new T[_size*2];
        _capacity*=2;
        for(size_t i=0; i<_size; i++)
            _values[i] = oldPtr[i];
        delete[] oldPtr;
    }
    _values[_size] = value;
    _size++;
}

template class Vector<int>;
template class Vector<float>;