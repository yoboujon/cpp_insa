#ifndef HEADER_VECTOR
#define HEADER_VECTOR

#include <cstddef>
#include <ostream>

template<class T>
class Vector{
public:
    Vector();
    Vector(size_t capacity);
    Vector(size_t capacity, T value);
    ~Vector();
    size_t Size();
    size_t Capacity();
    void PushBack(T value);
    template<class Tfriend>
    friend std::ostream& operator<<(std::ostream& stream, const Vector<Tfriend>& vec);
    template<class Tfriend>
    friend std::istream& operator>>(std::istream& stream, Vector<Tfriend>& vec);
private:
    T* _values;
    size_t _capacity;
    size_t _size;
};

template<class T>
Vector<T>::Vector() 
    : _capacity(1)
    , _size(0)
{
    // A vector must at least have a capacity of 1
    _values = new T[1];
}

template<class T>
Vector<T>::Vector(size_t capacity) 
    : _capacity(capacity)
    , _size(0)
{
    // Allocating the heap with the given capacity
    _values = new T[capacity];
}

template<class T>
Vector<T>::Vector(size_t capacity, T value) 
    : _capacity(capacity)
    , _size(capacity)
{
    // Allocating the heap and setting the value to each element.
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
size_t Vector<T>::Capacity() { return _capacity; }
template<class T>
size_t Vector<T>::Size() { return _size; }

template<class T>
void Vector<T>::PushBack(T value)
{
    // if the next size will overload the heap
    if (_capacity < _size+1)
    {
        // Keep a track of the old pointer
        T* oldPtr = _values;
        // Creating a new pointer by resizing its capacity by factor 2.
        _values = new T[_size*2];
        _capacity*=2;
        // Copying the old array onto the new
        for(size_t i=0; i<_size; i++)
            _values[i] = oldPtr[i];
        // Deallocating the old array
        delete[] oldPtr;
    }
    // Setting the given value and incrementing the size
    _values[_size] = value;
    _size++;
}

// methode get
template<class T>
std::ostream& operator<<(std::ostream& stream, const Vector<T>& vec)
{
    for(size_t i=0; i<vec._size; i++)
        stream << vec._values[i] << ", ";
    return stream;
}

// methode put
template<class T>
std::istream& operator>>(std::istream& stream, Vector<T>& vec)
{
    for(size_t i=0; i<vec._capacity; i++)
        stream >> vec._values[i];
    vec._size = vec._capacity;
    return stream;
}

#endif //HEADER_VECTOR