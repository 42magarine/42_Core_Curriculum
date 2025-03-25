#ifndef FWOOSH_H
#define FWOOSH_H

#include "ASpell.hpp"

class Fwoosh : public ASpell {
    public:
        Fwoosh();
        virtual ~Fwoosh();

        virtual Fwoosh* clone() const;
};

#endif // FWOOSH_H
