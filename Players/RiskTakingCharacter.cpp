#include "RiskTakingCharacter.h"


string RiskTakingCharacter::getDescription() const {
    return "RiskTaking";
}

int RiskTakingCharacter::handlePotionsMerchant(Player &player) const {
    if (player.getHealthPoints() >= CRITICAL_HEALTH_THRESHOLD) {
        return 0;
    }
    if (player.getCoins() < PotionsMerchant::HEALTH_POTION_PRICE) {
        return 0;
    }
    player.increaseHealthPointsBy(PotionsMerchant::HEALTH_POTION_HP_INCREASE);
    player.decreaseCoinsBy(PotionsMerchant::HEALTH_POTION_PRICE);
    return 1;
}