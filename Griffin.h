#pragma once
#include "GroundMount.h"
#include "FlyingMount.h"

// Ромбовидное наследование: FantasyMount <- GroundMount, FlyingMount <- Griffin
// (оба наследуют FantasyMount виртуально => один подобъект).
class LAB3_API Griffin : public GroundMount, public FlyingMount {
public:
    Griffin(const std::string& name, double x, double y, double baseSpeed,
            double terrainAdaptation, double flightAltitude, bool airborne = false);
    Griffin(const Griffin& other);
    Griffin& operator=(const Griffin& other);

    // move()/getSpeed()/describe() имеют два конечных переопределения -> Griffin обязан переопределить сам
    void move(double x, double y) override;
    double getSpeed() const override;
    std::string describe() const override;
    std::string typeName() const override;
    Griffin* clone() const override;

    void setAirborne(bool a);
    bool isAirborne() const;
private:
    bool airborne_;
};
