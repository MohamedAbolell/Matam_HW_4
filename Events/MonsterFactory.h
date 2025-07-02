#pragma once
#include "BaseFactory.h"
#include "Monster.h"
#include "Pack.h"

class MonsterFactory : public BaseFactory<Monster> {
public:
    MonsterFactory();
    std::unique_ptr<Pack> createPack(std::vector<std::unique_ptr<Monster> > &monsters);
};