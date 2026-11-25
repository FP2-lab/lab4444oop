#pragma once
#include "GroundMount.h"

class LAB3_API Horse : public GroundMount {
public:
    Horse(const std::string& name, double x, double y, double baseSpeed, double terrainAdaptation);
    Horse(const Horse& other);
    Horse& operator=(const Horse& other);
    std::string typeName() const override;
    Horse* clone() const override;
};
