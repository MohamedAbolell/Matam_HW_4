#pragma once
#include <string>
#include <memory>

class Monster {
protected:
    std::string formatStatsInDescription() const {
        return "(power " + std::to_string(getCombatPower()) + ", loot " + std::to_string(getLoot()) +
               ", damage " + std::to_string(getDamage()) + ")";
    }

public:
    virtual void applyPostEncounterEffect();

    virtual int getCombatPower() const = 0;

    virtual int getLoot() const = 0;

    virtual int getDamage() const = 0;

    virtual std::string getDescription() const = 0;

    virtual int getSize() const;

    virtual ~Monster() = default;
};
