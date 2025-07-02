#include "SpecialEventFactory.h"

#include "PotionsMerchant.h"
#include "SolarEclipse.h"

SpecialEventFactory::SpecialEventFactory() {
    creators = {
            {"SolarEclipse", []() { return std::make_unique<SolarEclipse>(); }},
            {"PotionsMerchant", []() { return std::make_unique<PotionsMerchant>(); }},
    };
}