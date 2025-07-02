#pragma once
#include "Monster.h"

class Balrog : public Monster {
    int combatPower = 15;
    const int LOOT = 100;
    const int DAMAGE = 9001;

public:
    int getCombatPower() const override;
    int getLoot() const override;
    int getDamage() const override;
    void applyPostEncounterEffect() override;
    std::string getDescription() const override;
};