#pragma once
#include "lab3_export.h"
#include <iosfwd>
#include <string>
#include <vector>

// Абстрактный базовый класс. От него наследуются виртуально (GroundMount, FlyingMount),
// поэтому в Griffin существует ровно один подобъект FantasyMount.
class LAB3_API FantasyMount {
public:
    virtual ~FantasyMount();

    // --- чисто виртуальные функции ---
    virtual void move(double x, double y) = 0;
    virtual double getSpeed() const = 0;
    virtual std::string typeName() const = 0;
    virtual FantasyMount* clone() const = 0;          // полиморфное копирование

    // --- виртуальная функция с реализацией по умолчанию ---
    virtual std::string describe() const;

    FantasyMount& operator=(const FantasyMount& other);   // копирует имя, координаты, параметры

    const std::string& getName() const;
    double getX() const;
    double getY() const;
    double getBaseSpeed() const;

    // --- статические члены (общая статистика) ---
    static double getTotalDistance();                 // общее расстояние всех существ
    static void resetTotalDistance();
    static int getAliveCount();                       // сколько объектов живо сейчас
    static int getCreatedCount();                     // сколько создано за всё время
    static std::string getFastestMountType();         // тип самого быстрого из живых экземпляров

    // --- дружественная функция ---
    friend LAB3_API std::ostream& operator<<(std::ostream& os, const FantasyMount& m);

protected:
    FantasyMount(const std::string& name, double x, double y, double baseSpeed);
    FantasyMount(const FantasyMount& other);

    // Перемещает в (x,y); к общему счётчику добавляет евклидово расстояние * factor.
    // Возвращает прямое расстояние.
    double travelTo(double x, double y, double factor);

private:
    static std::vector<const FantasyMount*>& registry();
    static double totalDistance_;
    static int aliveCount_;
    static int createdCount_;

    std::string name_;
    double x_, y_;
    double baseSpeed_;
};
