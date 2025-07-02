#pragma once

#include "../Players/Player.h"
#include <memory>
#include <string>

class Event {
public:
    virtual string handleAndDescribeOutcome(Player &player) = 0;

    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const = 0;

    virtual ~Event() = default;
};