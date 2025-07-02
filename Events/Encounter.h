#pragma once
#include "Event.h"
#include "Monster.h"

class Encounter : public Event {
    std::unique_ptr<Monster> monster;

public:
    explicit Encounter(std::unique_ptr<Monster> monster);

    string handleAndDescribeOutcome(Player &player) override;

    string getDescription() const override;
};