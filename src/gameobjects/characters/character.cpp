#include "gameobjects/characters/character.h"

Point2D Character::getCoords() {
    return coords_;
}

size_t Character::getHealth() {
    return health_;
}

void Character::setCoords(Point2D coords) {
    coords_ = coords;
}

void Character::setDamageDeal(int damageDeal) {
    damageDeal_ = damageDeal;
}

int Character::getDamageDeal() {
    return damageDeal_;
}

void Character::addDamageDeal(int damageDeal) {
    damageDeal_ += damageDeal;
}

void Character::setHealth(size_t health) {
    health_ = health;
}

void Character::decHealth(size_t health) {
    if (!health_)
        return;

    if (health_ - health * 1.5 < 0)
        health_ = 0;
    else
        health_ -= healthDebuff_ ? health * 1.5 : health;
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

void Character::move(Direction direction) {
    direction_ = direction;
    coords_.move(direction);
}

Direction Character::getDirection() {
    return direction_;
}

size_t Character::getPoints() {
    return points_;
}

void Character::setPoints(size_t points) {
    points_ = points;
}

void Character::setDirection(Direction direction) {
    direction_ = direction;
}

void Character::addPoints(size_t points) {
    points_ += points;
}

void Character::setEnd(bool value) {
    end_ = value;
}

bool Character::getEnd() {
    return end_ || !health_ || points_ >= 2;
}

std::string Character::toString() {
    return "Coords: " + getCoords().toString() + "\n" +
            "Points: " + std::to_string(getPoints()) + "\n" +
            "Health: " + std::to_string(getHealth()) + "\n" +
            "Health debuff: " + (getHealthDebuff() ? "yes" : "no") + '\n' +
            "End: " + (getEnd() ? "true" : "false") + "\n" +
            "Damage deal: " + std::to_string(getDamageDeal()) + "\n" +
            "Direction " + static_cast<char>(direction_);
}
