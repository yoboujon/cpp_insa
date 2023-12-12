#ifndef HEADER_PARTIE2
#define HEADER_PARTIE2

#include <map>
#include <cstdint>
#include <ostream>
#include <vector>

struct position {
    uint16_t x;
    uint16_t y;

    /**
     * @brief Used by std::map.
     * 
     * @param other the other position to check.
     * @return true Returns <x, if x is equal <y
     */
    bool operator<(const position& other) const {
        return (x!=other.x ? x<other.x : y<other.y);
    }
};

class MatriceCreuse {
    public:
        MatriceCreuse(uint16_t lines, uint16_t columns);
        MatriceCreuse(uint16_t lines, uint16_t columns, const std::map<position,int64_t>& values);
        MatriceCreuse(uint16_t lines, uint16_t columns, const std::vector<position>& positions, int64_t value);
        ~MatriceCreuse();
        friend std::ostream& operator<<(std::ostream& stream, MatriceCreuse matrice);
        int64_t& operator()(uint16_t x, uint16_t y);
        int64_t& operator[](position pos);
        MatriceCreuse operator*(int64_t val);
        MatriceCreuse operator+(int64_t val);
        MatriceCreuse operator-(int64_t val);
        MatriceCreuse operator+(MatriceCreuse other);
        MatriceCreuse operator-(MatriceCreuse other);
        MatriceCreuse& operator+=(int64_t val);
    private:
        void addValue(position pos, int64_t value);
        bool isSameDimension(const MatriceCreuse& other);

        uint16_t _line;
        uint16_t _column;
        std::map<position,int64_t> _values;
};

#endif // HEADER_PARTIE2