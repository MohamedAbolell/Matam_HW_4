#include "Pack.h"

Pack::Pack(std::vector<std::unique_ptr<Monster> > &monsters) {
    setMonsters(monsters);
}

void Pack::setMonsters(std::vector<std::unique_ptr<Monster> > &monsters) {
    std::for_each(monsters.begin(), monsters.end(), [this](auto &monster) {
        this->monsters.push_back(std::move(monster));
    });
}

int Pack::getSize() const {
    int size = 0;
    std::for_each(monsters.begin(), monsters.end(),
                  [&size](const auto &monster) { size += monster->getSize(); });
    return size;
}

int Pack::getCombatPower() const {
    int sum = 0;
    std::for_each(monsters.begin(), monsters.end(),
                  [&sum](const auto &monster) { sum += monster->getCombatPower(); });
    return sum;
}

int Pack::getLoot() const {
    int sum = 0;
    std::for_each(monsters.begin(), monsters.end(),
                  [&sum](const auto &monster) { sum += monster->getLoot(); });
    return sum;
}

int Pack::getDamage() const {
    int sum = 0;
    std::for_each(monsters.begin(), monsters.end(),
                  [&sum](const auto &monster) { sum += monster->getDamage(); });
    return sum;
}

void Pack::applyPostEncounterEffect() {
    std::for_each(monsters.begin(), monsters.end(),
                  [](auto &monster) { monster->applyPostEncounterEffect(); });
}

std::string Pack::getDescription() const {
    return "Pack of " + std::to_string(getSize()) + " members "
           + formatStatsInDescription();
}
