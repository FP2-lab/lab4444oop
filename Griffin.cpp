#include "Griffin.h"
#include <sstream>

Griffin::Griffin(const std::string& n, double x, double y, double s, double t, double a, bool air)
    : FantasyMount(n, x, y, s), GroundMount(n, x, y, s, t), FlyingMount(n, x, y, s, a), airborne_(air) {}

Griffin::Griffin(const Griffin& o)
    : FantasyMount(o), GroundMount(o), FlyingMount(o), airborne_(o.airborne_) {}

Griffin& Griffin::operator=(const Griffin& o) {
    if (this != &o) {
        // Виртуальная база присваивается дважды (через обе ветви) - это безопасно, т.к. значения идентичны.
        GroundMount::operator=(o);
        FlyingMount::operator=(o);
        airborne_ = o.airborne_;
    }
    return *this;
}

void Griffin::move(double x, double y) {
    if (airborne_) FlyingMount::move(x, y); else GroundMount::move(x, y);
}
double Griffin::getSpeed() const {
    return airborne_ ? FlyingMount::getSpeed() : GroundMount::getSpeed();
}
std::string Griffin::describe() const {
    std::ostringstream s;
    s << FantasyMount::describe() << " terrain=" << getTerrainAdaptation()
      << " altitude=" << getFlightAltitude() << " mode=" << (airborne_ ? "air" : "ground");
    return s.str();
}
std::string Griffin::typeName() const { return "Griffin"; }
Griffin* Griffin::clone() const { return new Griffin(*this); }
void Griffin::setAirborne(bool a) { airborne_ = a; }
bool Griffin::isAirborne() const { return airborne_; }
