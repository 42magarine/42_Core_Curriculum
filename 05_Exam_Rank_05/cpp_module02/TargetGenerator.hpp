#ifndef TARGETGENERATOR_H
#define TARGETGENERATOR_H

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* target);
        void forgetTargetType(const std::string& target_type);
        ATarget* createTarget(const std::string& target_type);

    private:
        TargetGenerator(const TargetGenerator& other);
        TargetGenerator& operator=(const TargetGenerator& other);

        std::map<std::string, ATarget*> _targets;
};

#endif // TARGETGENERATOR_H
