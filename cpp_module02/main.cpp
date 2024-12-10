#include "Warlock.hpp"
#include "SpellBook.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"

int main() {
    Warlock richard("Richard", "foo");
    richard.setTitle("Hello, I'm Richard the Warlock!");

    BrickWall model1;
    TargetGenerator tarGen;
    tarGen.learnTargetType(&model1);
    ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

    Fireball* fireball = new Fireball();
    richard.learnSpell(fireball);

    Polymorph* polymorph = new Polymorph();
    richard.learnSpell(polymorph);

    richard.introduce();
    richard.launchSpell("Polymorph", *wall);
    richard.launchSpell("Fireball", *wall);

    // delete wall;
    delete fireball;
    delete polymorph;
    return 0;
}
