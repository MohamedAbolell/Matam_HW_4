#pragma once
#include <memory>
#include <functional>
#include <set>
#include <map>

// I would declare this class outside of Event folder as it is also used in the Players folder,
// but I don't want to do that as the only outside files I can sumbit are MatamStory.h/.cpp, and
// including it there creates circular dependencies and I would like to not deal with it
template<typename T>
class BaseFactory {
public:
    using Creator = std::function<std::unique_ptr<T>()>;


    std::unique_ptr<T> create(const std::string &name) const {
        auto it = creators.find(name);
        if (it != creators.end()) {
            return it->second();
        }
        return nullptr;
    }

    std::set<std::string> getNames() const {
        std::set<std::string> names;
        for (const auto &pair: creators) {
            names.insert(pair.first);
        }
        return names;
    }

protected:
    std::map<std::string, Creator> creators;
};