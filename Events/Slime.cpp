#include "Slime.h"

int Slime::getCombatPower() const {
    return COMBAT_POWER;
}

int Slime::getDamage() const {
    return DAMAGE;
}

int Slime::getLoot() const {
    return LOOT;
}

std::string Slime::getDescription() const {
    return "Slime " + formatStatsInDescription();
}
