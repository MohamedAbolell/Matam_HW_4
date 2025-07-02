#include "MatamStory.h"

#include <algorithm>
#include <stdexcept>
#include <istream>
#include "Utilities.h"
#include "Events/Balrog.h"
#include "Events/Encounter.h"
#include "Events/MonsterFactory.h"
#include "Events/Pack.h"
#include "Events/PotionsMerchant.h"
#include "Events/Slime.h"
#include "Events/Snail.h"
#include "Players/RiskTakingCharacter.h"
#include "Players/Warrior.h"

using std::unique_ptr;

MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream) {
    string eventPrefix;
    while (eventsStream >> eventPrefix) {
        events.push_back(parseEvent(eventPrefix, eventsStream));
    }

    if (events.size() < MINIMUM_EVENTS_SIZE) {
        throw std::runtime_error(INVALID_EVENTS_FILE_ERROR);
    }
    string playerName;
    while (playersStream >> playerName) {
        auto player = parsePlayer(playerName, playersStream);
        activePlayers.push_back(player);
        allPlayers.push_back(player);
    }

    if (activePlayers.size() < MINIMUM_PLAYERS_SIZE || activePlayers.size() > MAXIMUM_PLAYERS_SIZE) {
        throw std::runtime_error(INVALID_PLAYERS_FILE_ERROR);
    }
    this->m_turnIndex = 1;
}

std::unique_ptr<Event> MatamStory::parseEvent(const string &eventPrefix,
                                              std::istream &eventsStream) {
    std::set<string> monsterNames = monsterFactory.getNames();
    if (monsterNames.find(eventPrefix) != monsterNames.end()) {
        auto monster = parseMonster(eventPrefix, eventsStream);
        return std::make_unique<Encounter>(std::move(monster));
    }

    unique_ptr<SpecialEvent> event = specialEventFactory.create(eventPrefix);
    if (event == nullptr) {
        throw std::runtime_error(INVALID_EVENTS_FILE_ERROR);
    }
    return std::move(event);
}


std::unique_ptr<Monster> MatamStory::parseMonster(const std::string &monsterName, std::istream &eventsStream) {
    if (monsterName == "Pack") {
        int quantity;
        if (!(eventsStream >> quantity) || quantity < 1) {
            throw std::runtime_error(INVALID_EVENTS_FILE_ERROR);
        }
        std::vector<unique_ptr<Monster> > monsters;

        std::string packMember;
        for (int i = 0; i < quantity; ++i) {
            if (!(eventsStream >> packMember)) {
                throw std::runtime_error(INVALID_EVENTS_FILE_ERROR);
            }
            monsters.push_back(parseMonster(packMember, eventsStream));
        }
        unique_ptr<Pack> pack = monsterFactory.createPack(monsters);
        return std::move(pack);
    }

    auto monster = monsterFactory.create(monsterName);
    if (monster == nullptr) {
        // Invalid monster name
        throw std::runtime_error(INVALID_EVENTS_FILE_ERROR);
    }
    return monster;
}

shared_ptr<Player> MatamStory::parsePlayer(const string &playerName, std::istream &playersStream) {
    if (playerName.length() > MAXIMUM_PLAYER_NAME_LENGTH || playerName.length() < MINIMUM_PLAYER_NAME_LENGTH) {
        throw std::runtime_error(INVALID_PLAYERS_FILE_ERROR);
    }
    if (!std::all_of(playerName.begin(), playerName.end(),
                     [](const unsigned char c)-> bool { return isalpha(c); })) {
        throw std::runtime_error(INVALID_PLAYERS_FILE_ERROR);
    }


    string jobName, characterName;
    if (!(playersStream >> jobName)) {
        throw std::runtime_error(INVALID_PLAYERS_FILE_ERROR);
    }
    if (!(playersStream >> characterName)) {
        throw std::runtime_error(INVALID_PLAYERS_FILE_ERROR);
    }
    auto character = characterFactory.create(characterName);
    if (character == nullptr) {
        throw std::runtime_error(INVALID_PLAYERS_FILE_ERROR);
    }
    auto job = jobFactory.create(jobName);
    return std::make_shared<Player>(playerName, std::move(job), std::move(character));
}
void MatamStory::printCharacterIntros() const {
    int orderNumber = 1;
    for (const auto &player: activePlayers) {
        printStartPlayerEntry(orderNumber++, *(player));
    }
}

void MatamStory::sortPlayersAndPrintLeaderboard() {
    sortAllPlayers();
    printLeaderBoardMessage();
    // printing from the end ("largest") to the beginning ("smallest")
    int place = 1;
    for (auto it = allPlayers.rbegin(); it != allPlayers.rend(); ++it, ++place) {
        printLeaderBoardEntry(place, **it);
    }
}

std::vector<shared_ptr<Player> > MatamStory::getAllPlayers() const {
    return allPlayers;
}

const std::deque<shared_ptr<Player> > &MatamStory::getActivePlayers() const {
    return activePlayers;
}

const std::deque<unique_ptr<Event> > &MatamStory::getEvents() const {
    return events;
}

bool MatamStory::weHaveAWinner() const {
    return std::any_of(
            allPlayers.begin(), allPlayers.end(),
            [this](const shared_ptr<Player> &player) {
                return player->getLevel() == MAXIMUM_LEVEL;
            }
    );
}

void MatamStory::playTurn(Player &player) {
    // Get the first event at the head and put it at the back
    unique_ptr<Event> currentEvent = std::move(events.front());
    events.pop_front();

    // Handle event
    printTurnDetails(m_turnIndex, player, *currentEvent);
    printTurnOutcome(currentEvent->handleAndDescribeOutcome(player));
    events.push_back(std::move(currentEvent));
    m_turnIndex++;
}


