#pragma once
#include <memory>
#include "Player.h"

class Character {
public:
    // Returns amount of potions bought
    virtual int handlePotionsMerchant(Player &player) const = 0;

    virtual string getDescription() const = 0;

    virtual ~Character() = default;
};