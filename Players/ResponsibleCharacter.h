#pragma once
#include "Character.h"

class ResponsibleCharacter : public Character {
public:
    std::string getDescription() const override;

    int handlePotionsMerchant(Player &player) const override;
};