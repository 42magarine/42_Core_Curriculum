#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); it++) {
        delete it->second;
    }
}

void SpellBook::learnSpell(ASpell* spell) {
    if (spell) {
        _spells[spell->getName()] = spell->clone();
    }
}

void SpellBook::forgetSpell(const std::string& spell_name) {
    std::map<std::string, ASpell*>::iterator it = _spells.find(spell_name);
    if (it != _spells.end()) {
        delete it->second;
        _spells.erase(it);
    }
}

ASpell* SpellBook::createSpell(const std::string& spell_name) {
    std::map<std::string, ASpell*>::iterator it = _spells.find(spell_name);
    if (it != _spells.end()) {
        return it->second->clone();
    }
    return 0;
}
