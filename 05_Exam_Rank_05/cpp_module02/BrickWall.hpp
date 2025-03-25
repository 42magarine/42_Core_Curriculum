#ifndef BRICKWALL_H
#define BRICKWALL_H

#include "ATarget.hpp"

class BrickWall : public ATarget {
    public:
        BrickWall();
        virtual ~BrickWall();

        virtual BrickWall* clone() const;
};

#endif // BRICKWALL_H
