#include "MonsterFactory.h"

#include "Balrog.h"
#include "Pack.h"
#include "Slime.h"
#include "Snail.h"

MonsterFactory::MonsterFactory() {
    creators = {
            {"Snail", []() { return std::make_unique<Snail>(); }},
            {"Slime", []() { return std::make_unique<Slime>(); }},
            {"Balrog", []() { return std::make_unique<Balrog>(); }},
            {"Pack", []() { return std::make_unique<Pack>(); }},
    };
}

std::unique_ptr<Pack> MonsterFactory::createPack(std::vector<std::unique_ptr<Monster> > &monsters) {
    return std::make_unique<Pack>(monsters);
}