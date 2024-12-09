#include "ASpell.hpp"

ASpell::ASpell(const std::string& name, const std::string& effects) : _name(name), _effects(effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(const ASpell& other) : _name(other._name), _effects(other._effects) {}

ASpell& ASpell::operator=(const ASpell& other) {
    if (this != &other) {
        _name = other._name;
        _effects = other._effects;
    }
    return *this;
}

const std::string& ASpell::getName() const{
    return _name;
}

const std::string& ASpell::getEffects() const{
    return _effects;
}

void ASpell::launch(const ATarget& target) {
    target.getHitBySpell(*this);
}
