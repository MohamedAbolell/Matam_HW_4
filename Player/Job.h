#pragma once
#include <memory>
#include "../Events/Monster.h"
#include "Player.h"

class Job {
protected:
    const Stats DEFAULT_STATS = Stats{
            100,
            100,
            1,
            5,
            10
    };

public:
    virtual void winEncounter(Player &player, const std::unique_ptr<Monster> &) const;

    virtual void loseEncounter(Player &player, const std::unique_ptr<Monster> &) const;

    virtual int calculateCombatPower(const Player &player) const;

    virtual const Stats &getDefaultStats() const;

    virtual string getDescription() const = 0;

    virtual int handleSolarEclipse(Player &player) const;

    virtual ~Job() = default;
};