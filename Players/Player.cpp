#include "Player.h"

#include <set>
#include <stdexcept>
#include "Job.h"
#include "Character.h"
#include "Warrior.h"


string Player::getDescription() const {
    return name + ", " + job->getDescription() +
           " with " + character->getDescription() + " character (level "
           + std::to_string(getLevel()) + ", force " + std::to_string(getForce()) + ")";
}

string Player::getName() const {
    return name;
}

int Player::getLevel() const {
    return stats.level;
}

int Player::getForce() const {
    return stats.force;
}

int Player::getHealthPoints() const {
    return stats.currentHp;
}

int Player::getMaxHealthPoints() const {
    return stats.maxHp;
}

int Player::getCoins() const {
    return stats.coins;
}

bool Player::operator<(const Player &other) const {
    if (this->getLevel() != other.getLevel()) {
        return this->getLevel() < other.getLevel();
    }
    if (this->getCoins() != other.getCoins()) {
        return this->getCoins() < other.getCoins();
    }
    return this->getName() > other.getName();
}

void Player::setForce(int newForce) {
    if (newForce < 0) {
        stats.force = 0;
    } else {
        stats.force = newForce;
    }
}

void Player::increaseForceBy(int forceIncrease) {
    setForce(getForce() + forceIncrease);
}

void Player::decreaseForceBy(int forceDecrease) {
    setForce(getForce() - forceDecrease);
}

void Player::setHealthPoints(int newHealthPoints) {
    if (newHealthPoints > getMaxHealthPoints()) {
        stats.currentHp = getMaxHealthPoints();
    } else if (newHealthPoints < 0) {
        stats.currentHp = 0;
    } else {
        stats.currentHp = newHealthPoints;
    }
}

void Player::increaseHealthPointsBy(int hpIncrease) {
    setHealthPoints(getHealthPoints() + hpIncrease);
}

void Player::decreaseHealthPointsBy(int hpDecrease) {
    setHealthPoints(getHealthPoints() - hpDecrease);
}

void Player::increaseCoinsBy(int coinsIncrease) {
    setCoins(getCoins() + coinsIncrease);
}

void Player::decreaseCoinsBy(int coinsDecrease) {
    setCoins(getCoins() - coinsDecrease);
}

void Player::incrementLevel() {
    stats.level++;
}

void Player::setCoins(int newCoins) {
    if (newCoins < 0) {
        throw std::logic_error("WHERE IS MY MONEY?!");
    }
    stats.coins = newCoins;
}

Player::Player(const string &name, std::unique_ptr<Job> job, std::unique_ptr<Character> character): Player(
    name, std::move(job), std::move(character), Stats{}) {
    stats = this->getJob()->getDefaultStats();
}

Player::Player(const string &name, std::unique_ptr<Job> job, std::unique_ptr<Character> character,
               const Stats &stats): name(name), job(std::move(job)), character(std::move(character)), stats(stats) {
}

bool Player::isKnockedOut() const {
    return getHealthPoints() == 0;
}


const std::unique_ptr<Character> &Player::getCharacter() const {
    return character;
}

const std::unique_ptr<Job> &Player::getJob() const {
    return job;
}

const Stats &Player::getStats() const {
    return stats;
}
