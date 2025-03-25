#ifndef ATARGET_H
#define ATARGET_H

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
    public:
        ATarget(const std::string& type);
        virtual ~ATarget();

        ATarget(const ATarget& other);
        ATarget& operator=(const ATarget& other);

        const std::string& getType() const;

        virtual ATarget* clone() const = 0;

        void getHitBySpell(const ASpell& spell) const;

    protected:
        std::string _type;
};

#endif // ATARGET_H
