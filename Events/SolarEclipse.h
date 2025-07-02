#pragma once
#include "SpecialEvent.h"

class SolarEclipse : public SpecialEvent {
public:
    static const int SOLAR_ECLIPSE_FORCE_INCREASE = 1;
    static const int SOLAR_ECLIPSE_FORCE_DECREASE = 1;
    std::string handleAndDescribeOutcome(Player &player) override;
    string getDescription() const override;
};
