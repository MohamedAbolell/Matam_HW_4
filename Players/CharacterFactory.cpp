#include "CharacterFactory.h"

#include "ResponsibleCharacter.h"
#include "RiskTakingCharacter.h"

CharacterFactory::CharacterFactory() {
    creators = {
            {"RiskTaking", []() { return std::make_unique<RiskTakingCharacter>(); }},
            {"Responsible", []() { return std::make_unique<ResponsibleCharacter>(); }},
    };
}