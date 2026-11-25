#pragma once
#include "FantasyMount.h"

class LAB3_API FlyingMount : public virtual FantasyMount {
public:
    FlyingMount& operator=(const FlyingMount& other);
    void move(double x, double y) override;          // по прямой
    double getSpeed() const override;                // baseSpeed * (1 + altitude/1000)
    std::string describe() const override;
    double getFlightAltitude() const;
protected:
    FlyingMount(const std::string& name, double x, double y, double baseSpeed, double flightAltitude);
    FlyingMount(const FlyingMount& other);
private:
    double flightAltitude_;                          // >= 0
};
