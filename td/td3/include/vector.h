#ifndef HEADER_VECTOR
#define HEADER_VECTOR

#include <cstddef>
#include <ostream>

template <class T>
class Vector {
public:
    Vector();
    Vector(size_t capacity);
    Vector(size_t capacity, T value);
    Vector(const Vector<T>& other);
    ~Vector();
    size_t Size();
    size_t Capacity();
    void PushBack(T value);
    template <class Tfriend>
    friend std::ostream& operator<<(std::ostream& stream, const Vector<Tfriend>& vec);
    template <class Tfriend>
    friend std::istream& operator>>(std::istream& stream, Vector<Tfriend>& vec);
    Vector<T>& operator=(const Vector<T>& other);
    Vector<T>& operator()(const Vector<T>& other);
    T& operator[](const int indice);
    Vector<T> operator+(const Vector<T>& other);
    Vector<T>& operator+=(const Vector<T>& other);

protected:
    size_t _capacity;
    size_t _size;
    T* _values;
};

template <class T>
Vector<T>::Vector()
    : _capacity(1)
    , _size(0)
    , _values(new T[1])
{
}

template <class T>
Vector<T>::Vector(size_t capacity)
    : _capacity(capacity)
    , _size(0)
{
    // Allocating the heap with the given capacity
    _values = new T[capacity];
}

template <class T>
Vector<T>::Vector(size_t capacity, T value)
    : _capacity(capacity)
    , _size(capacity)
{
    // Allocating the heap and setting the value to each element.
    _values = new T[capacity];
    for (size_t i = 0; i < capacity; i++)
        _values[i] = value;
}

template <class T>
Vector<T>::Vector(const Vector& other)
    : _capacity(other._capacity)
    , _size(other._size)
    , _values(new T[other._capacity])
{
    for (size_t i = 0; i < other._size; i++)
        _values[i] = other._values[i];
}

template <class T>
Vector<T>::~Vector()
{
    delete[] _values;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other) {
        this->_capacity = other._capacity;
        this->_size = other._size;
        delete[] this->_values;
        this->_values = new T[other._capacity];
        for (size_t i = 0; i < other._size; i++)
            this->_values[i] = other._values[i];
    }
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator()(const Vector<T>& other)
{
    *this = other;
    return *this;
}

template <class T>
size_t Vector<T>::Capacity() { return _capacity; }
template <class T>
size_t Vector<T>::Size() { return _size; }

template <class T>
void Vector<T>::PushBack(T value)
{
    // if the next size will overload the heap
    if (_capacity < _size + 1) {
        // Keep a track of the old pointer
        T* oldPtr = _values;
        // Creating a new pointer by resizing its capacity by factor 2.
        _values = new T[_size * 2];
        _capacity *= 2;
        // Copying the old array onto the new
        for (size_t i = 0; i < _size; i++)
            _values[i] = oldPtr[i];
        // Deallocating the old array
        delete[] oldPtr;
    }
    // Setting the given value and incrementing the size
    _values[_size] = value;
    _size++;
}

// methode get
template <class T>
std::ostream& operator<<(std::ostream& stream, const Vector<T>& vec)
{
    for (size_t i = 0; i < vec._size; i++)
        stream << vec._values[i] << ", ";
    return stream;
}

// methode put
template <class T>
std::istream& operator>>(std::istream& stream, Vector<T>& vec)
{
    for (size_t i = 0; i < vec._capacity; i++)
        stream >> vec._values[i];
    vec._size = vec._capacity;
    return stream;
}

template <class T>
T& Vector<T>::operator[](const int indice)
{
    if (static_cast<size_t>(indice) > _size)
        throw "Indice from the vector is not reachable";
    else
        return _values[indice];
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
    if (_size != other._size)
        throw "Cannot add two vectors with different sizes together";
    else {
        Vector<T> returnVector(_size);
        returnVector._size = _size;
        for (size_t i = 0; i < _size; i++)
            returnVector._values[i] = _values[i] + other._values[i];
        return returnVector;
    }
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)
{
    if (_size != other._size)
        throw "Cannot add two vectors with different sizes together";
    else {
        for (size_t i = 0; i < _size; i++)
            _values[i] += other._values[i];
        return *this;
    }
}

#endif // HEADER_VECTOR