#pragma once
#include <string>
#include "MagicalCreature.h"
#include "RangedCombatJob.h"

class Magician : public RangedCombatJob, public MagicalCreature {
public:
    int handleSolarEclipse(Player &player) const override;
    string getDescription() const override;
};