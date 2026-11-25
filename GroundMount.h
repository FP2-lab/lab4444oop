#pragma once
#include "FantasyMount.h"

// Промежуточный класс. typeName() и clone() не реализованы => класс абстрактный.
class LAB3_API GroundMount : public virtual FantasyMount {
public:
    GroundMount& operator=(const GroundMount& other);
    void move(double x, double y) override;          // путь = расстояние / terrainAdaptation
    double getSpeed() const override;                // baseSpeed * terrainAdaptation
    std::string describe() const override;
    double getTerrainAdaptation() const;
protected:
    GroundMount(const std::string& name, double x, double y, double baseSpeed, double terrainAdaptation);
    GroundMount(const GroundMount& other);
private:
    double terrainAdaptation_;                       // (0, 1]
};
