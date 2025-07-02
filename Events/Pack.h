#pragma once
#include <vector>
#include <algorithm>

#include "Monster.h"

class Pack : public Monster {
    std::vector<std::unique_ptr<Monster> > monsters;

public:
    Pack(std::vector<std::unique_ptr<Monster> > &monsters);

    Pack() = default;

    void setMonsters(std::vector<std::unique_ptr<Monster> > &monsters);

    int getSize() const override;

    int getCombatPower() const override;

    int getLoot() const override;

    int getDamage() const override;

    void applyPostEncounterEffect() override;

    std::string getDescription() const override;
};
