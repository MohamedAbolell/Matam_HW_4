#pragma once
#include "BaseFactory.h"
#include "SpecialEvent.h"


class SpecialEventFactory : public BaseFactory<SpecialEvent> {
public:
    SpecialEventFactory();
};