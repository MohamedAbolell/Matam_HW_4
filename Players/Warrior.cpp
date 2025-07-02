#include "Warrior.h"

int Warrior::calculateCombatPower(const Player &player) const {
    return 2 * player.getForce() + player.getLevel();
}

string Warrior::getDescription() const {
    return "Warrior";
}

const Stats &Warrior::getDefaultStats() const {
    return WARRIOR_STATS;
}