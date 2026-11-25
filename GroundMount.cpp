#include "GroundMount.h"
#include "MountException.h"
#include <sstream>

GroundMount::GroundMount(const std::string& n, double x, double y, double s, double t)
    : FantasyMount(n, x, y, s), terrainAdaptation_(t) {
    if (t <= 0 || t > 1) throw MountException("terrainAdaptation должен быть в (0,1] (" + n + ")");
}

GroundMount::GroundMount(const GroundMount& o)
    : FantasyMount(o), terrainAdaptation_(o.terrainAdaptation_) {}

GroundMount& GroundMount::operator=(const GroundMount& o) {
    if (this != &o) {
        FantasyMount::operator=(o);
        terrainAdaptation_ = o.terrainAdaptation_;
    }
    return *this;
}

void GroundMount::move(double x, double y) { travelTo(x, y, 1.0 / terrainAdaptation_); }
double GroundMount::getSpeed() const { return getBaseSpeed() * terrainAdaptation_; }
double GroundMount::getTerrainAdaptation() const { return terrainAdaptation_; }

std::string GroundMount::describe() const {
    std::ostringstream s;
    s << FantasyMount::describe() << " terrain=" << terrainAdaptation_;
    return s.str();
}
