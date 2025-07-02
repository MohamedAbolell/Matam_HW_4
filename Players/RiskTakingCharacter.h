#pragma once

#include "Character.h"
#include "Player.h"
#include "../Events/PotionsMerchant.h"

class RiskTakingCharacter : public Character {
public:
    const int CRITICAL_HEALTH_THRESHOLD = 50;

    string getDescription() const override;

    int handlePotionsMerchant(Player &player) const override;
};