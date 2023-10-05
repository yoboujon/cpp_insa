#ifndef HEADER_POLYGONE
#define HEADER_POLYGONE

#include "figure.h"
#include <sys/types.h>

class Polygone : public Figure
{
    public:
        Polygone(u_int64_t nb_cotes);
        virtual std::string afficherCaracteristiques() override;
        virtual int perimetre() override;
    private:
        u_int64_t _nbcotes;
};

#endif // HEADER_POLYGONE