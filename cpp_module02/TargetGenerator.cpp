#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
    for (std::map<std::string, ATarget*>::iterator it = _targets.begin(); it != _targets.end(); it++) {
        delete it->second;
    }
}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (target) {
        _targets[target->getType()] = target->clone();
    }
}

void TargetGenerator::forgetTargetType(const std::string& target_type) {
    std::map<std::string, ATarget*>::iterator it = _targets.find(target_type);
    if (it != _targets.end()) {
        delete it->second;
        _targets.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(const std::string& target_type) {
    std::map<std::string, ATarget*>::iterator it = _targets.find(target_type);
    if (it != _targets.end()) {
        return it->second->clone();
    }
    return 0;
}
