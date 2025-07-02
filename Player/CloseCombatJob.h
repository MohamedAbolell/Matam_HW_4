#pragma once
#include "Job.h"

class CloseCombatJob : public Job {
    void applyCloseCombatPenalty(Player &player) const;

    const int CLOSE_COMBAT_HP_REDUCTION = 10;

public:
    void winEncounter(Player &player, const std::unique_ptr<Monster>&) const override;
};