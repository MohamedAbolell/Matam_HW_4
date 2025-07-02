#include "Encounter.h"

#include "../Utilities.h"
#include "../Players/Job.h"


Encounter::Encounter(std::unique_ptr<Monster> monster) : monster(std::move(monster)) {
}

string Encounter::handleAndDescribeOutcome(Player &player) {
    string message;
    if (player.getJob()->calculateCombatPower(player) > this->monster->getCombatPower()) {
        player.getJob()->winEncounter(player, monster);
        message = getEncounterWonMessage(player, monster->getLoot());
    } else {
        player.getJob()->loseEncounter(player, monster);
        message = getEncounterLostMessage(player, monster->getDamage());
    }
    monster->applyPostEncounterEffect();
    return message;
}

string Encounter::getDescription() const {
    return monster->getDescription();
}