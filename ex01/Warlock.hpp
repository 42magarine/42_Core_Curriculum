#ifndef WARLOCK_H
#define WARLOCK_H

#include <string>
#include <iostream>

class Warlock {
    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();

        const std::string& getName() const;
        const std::string& getTitle() const;

        void setTitle(const std::string& title);

        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(std::string spell);
        void launchSpell(std::string spell, ATarget& target);

    private:
        Warlock();
        Warlock(const Warlock& other);
        Warlock& operator=(const Warlock& other);

        std::string _name;
        std::string _title;
        
};

#endif // WALOCK_H
