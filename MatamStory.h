#pragma once
#include <map>
#include <set>
#include <deque>

#include "Events/Balrog.h"
#include "Players/Player.h"
#include "Events/Event.h"
#include "Events/MonsterFactory.h"
#include "Events/PotionsMerchant.h"
#include "Events/Slime.h"
#include "Events/Snail.h"
#include "Events/SolarEclipse.h"
#include "Events/SpecialEventFactory.h"
#include "Players/Archer.h"
#include "Players/CharacterFactory.h"
#include "Players/JobFactory.h"
#include "Players/Magician.h"
#include "Players/ResponsibleCharacter.h"
#include "Players/RiskTakingCharacter.h"
#include "Players/Warrior.h"

class MatamStory {
    SpecialEventFactory specialEventFactory;
    MonsterFactory monsterFactory;
    CharacterFactory characterFactory;
    JobFactory jobFactory;
    const std::string INVALID_EVENTS_FILE_ERROR = "Invalid Events File";
    const std::string INVALID_PLAYERS_FILE_ERROR = "Invalid Players File";

    const long unsigned int MINIMUM_EVENTS_SIZE = 2;
    const long unsigned int MINIMUM_PLAYERS_SIZE = 2;
    const long unsigned int MAXIMUM_PLAYERS_SIZE = 6;
    const long unsigned int MAXIMUM_PLAYER_NAME_LENGTH = 15;
    const long unsigned int MINIMUM_PLAYER_NAME_LENGTH = 3;
    const int MAXIMUM_LEVEL = 10;


    std::deque<std::unique_ptr<Event> > events;
    std::deque<shared_ptr<Player> > activePlayers;
    std::vector<shared_ptr<Player> > allPlayers;
    unsigned int m_turnIndex;

    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player &player);

    void removeInactivePlayers();

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

    void sortAllPlayers();

    bool weHaveAWinner() const;

    std::unique_ptr<Event> parseEvent(const string &eventPrefix, std::istream &eventsStream);

    std::unique_ptr<Monster> parseMonster(const string &monster, std::istream &eventsStream);

    std::shared_ptr<Player> parsePlayer(const string &playerName, std::istream &playersStream);


    const std::deque<shared_ptr<Player> > &getActivePlayers() const;

    std::vector<shared_ptr<Player> > getAllPlayers() const;

    const std::deque<std::unique_ptr<Event> > &getEvents() const;

    void printCharacterIntros() const;

    void sortPlayersAndPrintLeaderboard();

public:
    // we don't want to make copies of this class
    MatamStory(const MatamStory &) = delete;

    MatamStory &operator=(const MatamStory &) = delete;

    // and we don't want default initialization of it
    MatamStory() = delete;

    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream &eventsStream, std::istream &playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};