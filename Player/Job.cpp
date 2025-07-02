#include "Job.h"

#include "../Utilities.h"
#include "../Events/SolarEclipse.h"

void Job::winEncounter(Player &player, const std::unique_ptr<Monster> &monster) const {
    player.increaseCoinsBy(monster->getLoot());
    player.incrementLevel();
}

void Job::loseEncounter(Player &player, const std::unique_ptr<Monster> &monster) const {
    player.decreaseHealthPointsBy(monster->getDamage());
}

int Job::calculateCombatPower(const Player &player) const {
    return player.getForce() + player.getLevel();
}

const Stats &Job::getDefaultStats() const {
    return DEFAULT_STATS;
}

int Job::handleSolarEclipse(Player &player) const {
    if (player.getForce() == 0) {
        return 0;
    }
    player.decreaseForceBy(SolarEclipse::SOLAR_ECLIPSE_FORCE_DECREASE);
    return -1 * SolarEclipse::SOLAR_ECLIPSE_FORCE_DECREASE;
}