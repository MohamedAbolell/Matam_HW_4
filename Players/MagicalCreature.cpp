#include "MagicalCreature.h"

#include "../Utilities.h"
#include "../Events/SolarEclipse.h"

int MagicalCreature::handleSolarEclipse(Player &player) const {
    player.increaseForceBy(SolarEclipse::SOLAR_ECLIPSE_FORCE_INCREASE);
    return SolarEclipse::SOLAR_ECLIPSE_FORCE_INCREASE;
}