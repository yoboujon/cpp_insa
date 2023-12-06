#ifndef HEADER_FILE
#define HEADER_FILE

#include <cstddef>
#include <optional>
#include <string>

template <class T>
class File;

template <class T>
class Cellule {
public:
    friend File<T>;
    Cellule(T value)
        : _value(value)
        , _next(nullptr)
    {
    }
    Cellule(T value, Cellule* next)
        : _value(value)
        , _next(next)
    {
    }

private:
    T _value;
    Cellule* _next;
};

template <class T>
class Vide : Cellule<T> {
public:
    friend File<T>;
    Vide()
        : Cellule<T>(0)
    {
    }
};

template <class T>
class File {
public:
    File()
        : _size(0)
        , _front(nullptr)
        , _end(nullptr)
        , _vide() {};
    ~File()
    {
        auto next = _front;
        auto front = _front;

        while (next != nullptr) {
            next = front->_next;
            delete front;
            front = next;
        }
    }
    size_t getSize() { return _size; }
    bool isEmpty() { return _size < 1; }
    void push_back(T value)
    {
        auto newCell = new Cellule<T>(value, nullptr);
        if (_front == nullptr && _end == nullptr) {
            _front = newCell;
            _end = newCell;
        } else {
            _end->_next = newCell;
            _end = newCell;
        }
        _size++;
    }

    T& operator[](size_t index)
    {
        auto cell = getCell(index);
        if (cell.has_value())
            return cell.value()->_value;
        else
            return _vide._value;
    }

    void remove(size_t index)
    {
        auto actualCell = getCell(index);
        if (!actualCell.has_value())
            throw std::string("Cannot remove from an index superior to the File size.");
        // if not _front -> get previous index and set next to the next of this removed cell
        if (index > 0)
            getCell(index - 1).value()->_next = actualCell.value()->_next;
        // else, the front becomes this cell
        else
            _front = actualCell.value()->_next;
        // deleting the cell and decrementing the size
        delete actualCell.value();
        _size--;
    }

    T& getFront() { return _front->_value; }
    T& getEnd() { return _front->_value; }

private:
    std::optional<Cellule<T>*> getCell(size_t index)
    {
        auto returnCell = _front;
        if (index >= _size)
            return {};
        for (size_t i = 0; i < index; i++) {
            returnCell = returnCell->_next;
        }
        return returnCell;
    }

    size_t _size;
    Cellule<T>* _front;
    Cellule<T>* _end;
    Vide<T> _vide;
};

#endif // HEADER_FILE