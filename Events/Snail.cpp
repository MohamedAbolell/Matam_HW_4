#include "Snail.h"

int Snail::getDamage() const {
    return this->DAMAGE;
}

int Snail::getLoot() const {
    return this->LOOT;
}

int Snail::getCombatPower() const {
    return COMBAT_POWER;
}

std::string Snail::getDescription() const {
    return "Snail " + formatStatsInDescription();
}