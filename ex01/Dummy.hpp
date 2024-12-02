#ifndef DUMMY_H
#define DUMMY_H

#include "ATarget.hpp"

class Dummy : public ATarget {
    public:
        Dummy();
        ~Dummy();
        ATarget* clone() const;
};

#endif // DUMMY_H
