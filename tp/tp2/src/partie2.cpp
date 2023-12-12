#include "../include/partie2.h"

MatriceCreuse::MatriceCreuse(uint16_t lines, uint16_t columns)
    : _line(lines)
    , _column(columns)
{}

MatriceCreuse::MatriceCreuse(uint16_t lines, uint16_t columns, const std::map<position,int64_t>& values)
    : MatriceCreuse(lines,columns)
{
    for (const auto& val : values)
        addValue(val.first,val.second);
}

MatriceCreuse::MatriceCreuse(uint16_t lines, uint16_t columns, const std::vector<position>& positions, int64_t value)
    : MatriceCreuse(lines,columns)
{
    for(auto pos : positions)
        addValue(pos,value);
}

MatriceCreuse::~MatriceCreuse() {}

std::ostream& operator<<(std::ostream& stream, MatriceCreuse matrice)
{
    for(uint16_t x(0); x < matrice._column; x++)
    {
        for(uint16_t y(0); y < matrice._line; y++)
        {
            int64_t value = matrice._values.find({x,y}) != matrice._values.end() ? matrice._values[{x,y}] : 0 ;
            stream << "[" << value << "] ";
        }
        stream << "\n";
    }
    return stream;
}

int64_t& MatriceCreuse::operator()(uint16_t x, uint16_t y)
{
    if (_values.find({x,y}) == _values.end())
        _values[{x,y}] = 0;
    return _values[{x,y}];
}

int64_t& MatriceCreuse::operator[](position pos) { return (*this)(pos.x,pos.y); }

MatriceCreuse MatriceCreuse::operator+(int64_t val)
{
    auto newMatrix = *this;
    for(uint16_t x(0); x < _column; x++)
    {
        for(uint16_t y(0); y < _line; y++)
            newMatrix(x,y) = newMatrix(x,y) + val;
    }
    return newMatrix;
}

MatriceCreuse MatriceCreuse::operator-(int64_t val)
{
    return (*this)+(-val);
}

MatriceCreuse MatriceCreuse::operator+(MatriceCreuse other)
{
    if(!this->isSameDimension(other))
        throw "Could not '+' two matrixes with different dimensions!";
    auto newMatrix = *this;
    for(uint16_t x(0); x < _column; x++)
    {
        for(uint16_t y(0); y < _line; y++)
            newMatrix(x,y) = (*this)(x,y) + other(x,y);
    }
    return newMatrix;
}

MatriceCreuse MatriceCreuse::operator-(MatriceCreuse other)
{
    if(!this->isSameDimension(other))
        throw "Could not '-' two matrixes with different dimensions!";
    auto newMatrix = *this;
    for(uint16_t x(0); x < _column; x++)
    {
        for(uint16_t y(0); y < _line; y++)
            newMatrix(x,y) = (*this)(x,y) - other(x,y);
    }
    return newMatrix;
}

MatriceCreuse& MatriceCreuse::operator+=(int64_t val)
{
    for(uint16_t x(0); x < _column; x++)
    {
        for(uint16_t y(0); y < _line; y++)
            (*this)(x,y) = (*this)(x,y) + val;
    }
    return *this;
}

void MatriceCreuse::addValue(position pos, int64_t value)
{
    if((pos.x > _column-1) || (pos.y > _column-1))
        throw "Could not add value to the matrix because of matrix's length";
    _values[pos] = value;
}

bool MatriceCreuse::isSameDimension(const MatriceCreuse& other) { return (this->_column == other._column) && (this->_line == other._line); }