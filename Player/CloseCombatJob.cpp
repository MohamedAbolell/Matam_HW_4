#include "CloseCombatJob.h"

void CloseCombatJob::applyCloseCombatPenalty(Player &player) const {
    player.decreaseHealthPointsBy(this->CLOSE_COMBAT_HP_REDUCTION);
}

void CloseCombatJob::winEncounter(Player &player, const std::unique_ptr<Monster>& monster) const {
    Job::winEncounter(player, monster);
    applyCloseCombatPenalty(player);
}