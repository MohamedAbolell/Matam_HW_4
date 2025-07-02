#pragma once
#include "Job.h"
#include "../Events/BaseFactory.h"

class JobFactory : public BaseFactory<Job> {
public:
    JobFactory();
};