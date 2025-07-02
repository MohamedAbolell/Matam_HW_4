//
// Created by Oneg Vaknin on 02/07/2025.
//
#include "Magician.h"

int Magician::handleSolarEclipse(Player &player) const {
    return MagicalCreature::handleSolarEclipse(player);
}

string Magician::getDescription() const {
    return "Magician";
}
