#pragma once
#include "CloseCombatJob.h"


class Warrior : public CloseCombatJob {
    const Stats WARRIOR_STATS = Stats{
            150,
            150,
            1,
            5,
            10
    };

public:
    int calculateCombatPower(const Player &player) const override;

    string getDescription() const override;

    const Stats &getDefaultStats() const override;
};