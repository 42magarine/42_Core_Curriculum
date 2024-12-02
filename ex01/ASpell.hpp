#ifndef ASPELL_H
#define ASPELL_H

#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
    public:
        ASpell(const std::string& name, const std::string& effects);
        virtual ~ASpell();

        const std::string& getName() const;
        const std::string& getEffects() const;

        virtual ASpell* clone() const = 0;
        void launch(const ATarget& target);

    protected:
        ASpell();
        ASpell(const ASpell& other);
        ASpell& operator=(const ASpell& other);

        std::string _name;
        std::string _effects;
};

#endif // ASPELL_H
