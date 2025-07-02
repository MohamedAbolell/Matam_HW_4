#include "SolarEclipse.h"

#include "../Utilities.h"
#include "../Players/Job.h"

std::string SolarEclipse::handleAndDescribeOutcome(Player &player) {
    int forceChange = player.getJob()->handleSolarEclipse(player);
    return getSolarEclipseMessage(player, forceChange);
}

string SolarEclipse::getDescription() const {
    return "SolarEclipse";
}
