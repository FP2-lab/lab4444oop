#include "FlyingMount.h"
#include "MountException.h"
#include <sstream>

FlyingMount::FlyingMount(const std::string& n, double x, double y, double s, double a)
    : FantasyMount(n, x, y, s), flightAltitude_(a) {
    if (a < 0) throw MountException("flightAltitude не может быть < 0 (" + n + ")");
}

FlyingMount::FlyingMount(const FlyingMount& o)
    : FantasyMount(o), flightAltitude_(o.flightAltitude_) {}

FlyingMount& FlyingMount::operator=(const FlyingMount& o) {
    if (this != &o) {
        FantasyMount::operator=(o);
        flightAltitude_ = o.flightAltitude_;
    }
    return *this;
}

void FlyingMount::move(double x, double y) { travelTo(x, y, 1.0); }
double FlyingMount::getSpeed() const { return getBaseSpeed() * (1.0 + flightAltitude_ / 1000.0); }
double FlyingMount::getFlightAltitude() const { return flightAltitude_; }

std::string FlyingMount::describe() const {
    std::ostringstream s;
    s << FantasyMount::describe() << " altitude=" << flightAltitude_;
    return s.str();
}
