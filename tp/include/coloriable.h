#ifndef HEADER_COLORIABLE
#define HEADER_COLORIABLE
#include <string>

class Coloriable {
protected:
    std::string couleur;

public:
    Coloriable(std::string coul)
    {
        couleur = coul;
    }
    std::string getCouleur()
    {
        return couleur;
    }
    void setCouleur(std::string coul)
    {
        couleur = coul;
    }
};

#endif // HEADER_COLORIABLE