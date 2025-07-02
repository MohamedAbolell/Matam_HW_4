#pragma once
#include "Character.h"
#include "../Events/BaseFactory.h"

class CharacterFactory :public BaseFactory<Character> {
public:
    CharacterFactory();
};