#include "Archer.h"
string Archer::getDescription() const {
    return "Archer";
}

const Stats & Archer::getDefaultStats() const {
    return Archer_STATS;
}
