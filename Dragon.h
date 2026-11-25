#pragma once
#include "FlyingMount.h"

class LAB3_API Dragon : public FlyingMount {
public:
    Dragon(const std::string& name, double x, double y, double baseSpeed, double flightAltitude);
    Dragon(const Dragon& other);
    Dragon& operator=(const Dragon& other);
    std::string typeName() const override;
    Dragon* clone() const override;
};
