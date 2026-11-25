#include "Horse.h"

Horse::Horse(const std::string& n, double x, double y, double s, double t)
    : FantasyMount(n, x, y, s), GroundMount(n, x, y, s, t) {}
Horse::Horse(const Horse& o) : FantasyMount(o), GroundMount(o) {}
Horse& Horse::operator=(const Horse& o) { GroundMount::operator=(o); return *this; }
std::string Horse::typeName() const { return "Horse"; }
Horse* Horse::clone() const { return new Horse(*this); }
