#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spell_name);
        ASpell* createSpell(const std::string& spell_name);

    private:
        SpellBook(const SpellBook& other);
        SpellBook& operator=(const SpellBook& other);

        std::map<std::string, ASpell*> _spells;
};

#endif // SPELLBOOK_H
