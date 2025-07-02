#include "ResponsibleCharacter.h"

#include <algorithm>
#include "../Events/PotionsMerchant.h"

int ResponsibleCharacter::handlePotionsMerchant(Player &player) const {
    if (player.getHealthPoints() == player.getMaxHealthPoints()) {
        return 0;
    }
    int potionsBought = std::min(
            player.getCoins() / PotionsMerchant::HEALTH_POTION_PRICE,
            (player.getMaxHealthPoints() - player.getHealthPoints()) / PotionsMerchant::HEALTH_POTION_HP_INCREASE
    );
    if (potionsBought == 0 && player.getCoins() >= PotionsMerchant::HEALTH_POTION_PRICE) {
        potionsBought = 1;
    }
    player.increaseHealthPointsBy(potionsBought * PotionsMerchant::HEALTH_POTION_HP_INCREASE);
    player.decreaseCoinsBy(potionsBought * PotionsMerchant::HEALTH_POTION_PRICE);
    return potionsBought;
}

std::string ResponsibleCharacter::getDescription() const {
    return "Responsible";
}