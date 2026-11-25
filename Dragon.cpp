#include "Dragon.h"

Dragon::Dragon(const std::string& n, double x, double y, double s, double a)
    : FantasyMount(n, x, y, s), FlyingMount(n, x, y, s, a) {}
Dragon::Dragon(const Dragon& o) : FantasyMount(o), FlyingMount(o) {}
Dragon& Dragon::operator=(const Dragon& o) { FlyingMount::operator=(o); return *this; }
std::string Dragon::typeName() const { return "Dragon"; }
Dragon* Dragon::clone() const { return new Dragon(*this); }
