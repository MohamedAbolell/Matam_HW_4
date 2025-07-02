#pragma once
#include "Monster.h"

class Slime : public Monster {
    const int COMBAT_POWER = 12;
    const int LOOT = 5;
    const int DAMAGE = 25;

public:
    int getCombatPower() const override;

    int getDamage() const override;

    int getLoot() const override;

    std::string getDescription() const override;
};
