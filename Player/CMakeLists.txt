cmake_minimum_required(VERSION 3.29)
project(Players)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Players
        Archer.cpp
        Archer.h
        Character.h
        CharacterFactory.cpp
        CharacterFactory.h
        CloseCombatJob.cpp
        CloseCombatJob.h
        Job.cpp
        Job.h
        JobFactory.cpp
        JobFactory.h
        MagicalCreature.cpp
        MagicalCreature.h
        Magician.cpp
        Magician.h
        Player.cpp
        Player.h
        RangedCombatJob.h
        ResponsibleCharacter.cpp
        ResponsibleCharacter.h
        RiskTakingCharacter.cpp
        RiskTakingCharacter.h
        Stats.h
        Warrior.cpp
        Warrior.h)
