#pragma once
#include "SpecialEvent.h"


class PotionsMerchant : public SpecialEvent {
public:
    static const int HEALTH_POTION_PRICE = 5;
    static const int HEALTH_POTION_HP_INCREASE = 10;

    string handleAndDescribeOutcome(Player &player) override;

    string getDescription() const override;
};
