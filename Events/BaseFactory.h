#pragma once
#include <memory>
#include <functional>
#include <set>
#include <map>

// Ideally, I would place this class outside the Event folder since it's also needed in the Players folder.
// However, I'm limited to only submitting external files named MatamStory.h/.cpp.
// Including the class there leads to circular dependencies, which I'd prefer to avoid.
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