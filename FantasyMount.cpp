#include "FantasyMount.h"
#include "MountException.h"
#include <algorithm>
#include <cmath>
#include <ostream>
#include <sstream>

double FantasyMount::totalDistance_ = 0.0;
int FantasyMount::aliveCount_ = 0;
int FantasyMount::createdCount_ = 0;

std::vector<const FantasyMount*>& FantasyMount::registry() {
    static std::vector<const FantasyMount*> r;   // function-local: нет проблем с порядком инициализации
    return r;
}

FantasyMount::FantasyMount(const std::string& name, double x, double y, double baseSpeed)
    : name_(name), x_(x), y_(y), baseSpeed_(baseSpeed) {
    if (name.empty()) throw MountException("Пустое имя существа");
    if (baseSpeed <= 0) throw MountException("Скорость должна быть > 0 (" + name + ")");
    registry().push_back(this);
    ++aliveCount_;
    ++createdCount_;
}

FantasyMount::FantasyMount(const FantasyMount& o)
    : name_(o.name_), x_(o.x_), y_(o.y_), baseSpeed_(o.baseSpeed_) {
    registry().push_back(this);
    ++aliveCount_;
    ++createdCount_;
}

FantasyMount::~FantasyMount() {
    auto& r = registry();
    r.erase(std::remove(r.begin(), r.end(), this), r.end());
    --aliveCount_;
}

FantasyMount& FantasyMount::operator=(const FantasyMount& o) {
    if (this != &o) {
        name_ = o.name_; x_ = o.x_; y_ = o.y_; baseSpeed_ = o.baseSpeed_;
    }
    return *this;   // регистрация и счётчики не трогаем: объект тот же
}

std::string FantasyMount::describe() const {
    std::ostringstream s;
    s << typeName() << " '" << name_ << "' pos=(" << x_ << ", " << y_ << ") speed=" << getSpeed();
    return s.str();
}

const std::string& FantasyMount::getName() const { return name_; }
double FantasyMount::getX() const { return x_; }
double FantasyMount::getY() const { return y_; }
double FantasyMount::getBaseSpeed() const { return baseSpeed_; }

double FantasyMount::travelTo(double x, double y, double factor) {
    double d = std::hypot(x - x_, y - y_);
    x_ = x; y_ = y;
    totalDistance_ += d * factor;
    return d;
}

double FantasyMount::getTotalDistance() { return totalDistance_; }
void FantasyMount::resetTotalDistance() { totalDistance_ = 0.0; }
int FantasyMount::getAliveCount() { return aliveCount_; }
int FantasyMount::getCreatedCount() { return createdCount_; }

std::string FantasyMount::getFastestMountType() {
    const FantasyMount* best = nullptr;
    for (const FantasyMount* m : registry())
        if (!best || m->getSpeed() > best->getSpeed()) best = m;
    return best ? best->typeName() : "none";
}

std::ostream& operator<<(std::ostream& os, const FantasyMount& m) {
    return os << m.describe();     // доступ к приватным данным не нужен, но friend по заданию
}
