#include "gameobjects/character.h"

Point2D Character::getCoords() {
    return coords_;
}

size_t Character::getHealth() {
    return health_;
}

void Character::setCoords(Point2D coords) {
    coords_ = coords;
}

void Character::setHealth(size_t health) {
    health_ = health;
}

void Character::decHealth(size_t health) {
    if (!health_)
        return;

    health_ -= health;
}

bool Character::getHealthDebuff() {
    return healthDebuff_;
}

void Character::decPoints(size_t points) {
    if (!points_)
        return;

    points_ -= points;
}

void Character::setHealthDebuff(bool debuff) {
    healthDebuff_ = debuff;
}

void Character::move(DIRECTION direction) {
    switch (direction) {
        case UP:
            coords_ += Point2D(0, -1);
            break;
        case LEFT:
            coords_ += Point2D(-1, 0);
            break;
        case DOWN:
            coords_ += Point2D(0, 1);
            break;
        case RIGHT:
            coords_ += Point2D(1, 0);
            break;
        default:
            break;;
    }
}

size_t Character::getPoints() {
    return points_;
}

void Character::setPoints(size_t points) {
    points_ = points;
}

void Character::addPoints(size_t points) {
    points_ += points;
    if (points_ >= 2)
        end_ = true;
}

void Character::setEnd(bool value) {
    end_ = value;
}

bool Character::getEnd() {
    return end_ || !health_;
}
