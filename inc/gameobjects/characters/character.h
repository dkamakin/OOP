#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include "utilities/point2d.h"
#include "controller/direction.h"

using sCharacter = std::shared_ptr <class Character>;

class Character {
    size_t points_;
    size_t health_;
    Point2D coords_;
    Direction direction_;
    bool end_;
    bool healthDebuff_;

public:
    Character() = default;

    void move(Direction direction);

    Direction getDirection();
    std::string toString();
    Point2D getCoords();
    size_t getHealth();
    size_t getPoints();
    bool getHealthDebuff();
    bool getEnd();

    void setCoords(Point2D coords);
    void setHealth(size_t heath);
    void setDirection(Direction direction);
    void setPoints(size_t points);
    void addPoints(size_t points);
    void setEnd(bool value);
    void decHealth(size_t health);
    void decPoints(size_t points);
    void setHealthDebuff(bool debuff);
};

#endif // CHARACTER_H