#ifndef HEADER_FIGURE
#define HEADER_FIGURE

#include <string>

class Figure {
    public:
        virtual float perimetre()=0;
        virtual std::string afficherCaracteristiques()=0;
};

#endif // HEADER_FIGURE