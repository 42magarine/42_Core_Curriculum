#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();

        const std::string& getName() const;
        const std::string& getTitle() const;

        void setTitle(const std::string& title);

        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spell_name);
        void launchSpell(const std::string& spell_name, const ATarget& target);

    private:
        Warlock();
        Warlock(const Warlock& other);
        Warlock& operator=(const Warlock& other);

        std::string _name;
        std::string _title;
        SpellBook _spell_book;
};

#endif // WARLOCK_H
