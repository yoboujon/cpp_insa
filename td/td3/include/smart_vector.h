#ifndef HEADER_SMART_VECTOR
#define HEADER_SMART_VECTOR

#include "vector.h"

template <class T>
class Smart_Vector : public Vector<T> {
    public:
        Smart_Vector<T> operator+(const Smart_Vector<T>& other);
        Smart_Vector<T>& operator+=(const Smart_Vector<T>& other);
};

#endif // HEADER_SMART_VECTOR