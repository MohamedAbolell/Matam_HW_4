#include "Balrog.h"

int Balrog::getCombatPower() const {
    return combatPower;
}

int Balrog::getLoot() const {
    return LOOT;
}

int Balrog::getDamage() const {
    return DAMAGE;
}

void Balrog::applyPostEncounterEffect() {
    combatPower += 2;
}

std::string Balrog::getDescription() const {
    return "Balrog " + formatStatsInDescription();
}
