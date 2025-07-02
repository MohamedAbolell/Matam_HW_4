#pragma once
#include "RangedCombatJob.h"

class Archer : public RangedCombatJob {
    const Stats Archer_STATS = Stats{
        100,
        100,
        1,
        5,
        20
    };

public:
    string getDescription() const override;

    const Stats &getDefaultStats() const override;
};
