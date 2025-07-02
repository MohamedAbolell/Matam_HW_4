#include "PotionsMerchant.h"

#include "../Utilities.h"
#include "../Players/Character.h"

string PotionsMerchant::handleAndDescribeOutcome(Player &player) {
    int amountBought = player.getCharacter()->handlePotionsMerchant(player);
    return getPotionsPurchaseMessage(player, amountBought);
}

string PotionsMerchant::getDescription() const {
    return "PotionsMerchant";
}