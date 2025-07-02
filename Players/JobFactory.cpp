#include "JobFactory.h"

#include "Archer.h"
#include "Magician.h"
#include "Warrior.h"

JobFactory::JobFactory() {
    creators = {
            {"Warrior", []() { return std::make_unique<Warrior>(); }},
            {"Archer", []() { return std::make_unique<Archer>(); }},
            {"Magician", []() { return std::make_unique<Magician>(); }},
    };
}
