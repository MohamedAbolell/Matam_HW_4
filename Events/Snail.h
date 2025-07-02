#pragma once
#include "Monster.h"

class Snail : public Monster {
    const int COMBAT_POWER = 5;
    const int LOOT = 2;
    const int DAMAGE = 10;

public:
    int getDamage() const override;

    int getLoot() const override;

    int getCombatPower() const override;

    std::string getDescription() const override;
};