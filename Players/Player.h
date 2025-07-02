
#pragma once

#include <string>
#include <memory>
#include "Stats.h"

using std::string;
using std::shared_ptr;

class Job;
class Character;

class Player {
    string name;
    std::unique_ptr<Job> job;
    std::unique_ptr<Character> character;
    Stats stats;

    void setForce(int newForce);

    void setHealthPoints(int newHealthPoints);

    void setCoins(int newCoins);

public:
    Player(const string &name, std::unique_ptr<Job> job, std::unique_ptr<Character> character);

    Player(const string &name, std::unique_ptr<Job> job, std::unique_ptr<Character> character,
           const Stats &stats);

    bool isKnockedOut() const;

    const Stats &getStats() const;

    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    int getMaxHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;

    bool operator<(const Player &) const;

    void increaseForceBy(int forceIncrease);

    void decreaseForceBy(int forceDecrease);

    void increaseHealthPointsBy(int hpIncrease);

    void decreaseHealthPointsBy(int hpDecrease);

    void increaseCoinsBy(int coinsIncrease);

    void decreaseCoinsBy(int coinsDecrease);

    void incrementLevel();

    const std::unique_ptr<Character> &getCharacter() const;

    const std::unique_ptr<Job> &getJob() const;
};
