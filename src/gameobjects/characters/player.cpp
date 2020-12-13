#include "gameobjects/characters/player.h"

Player::Player(Point2D coords, size_t health, sInteractStrategy strategy) {
    setPoints(0);
    setCoords(coords);
    setHealth(health);
    setHealthDebuff(false);
    setEnd(false);
    strategy_ = strategy;
}

void Player::setStrategy(sInteractStrategy strategy) {
    strategy_ = strategy;
}

void Player::operator+=(sGameObject &right) {
    if (!right || !strategy_)
        return;

    strategy_->interact(*this, right);
}

void Player::operator+=(sEnemyAbstract &right) {
    if (!right)
        return;

    right->decHealth(10);
}

std::ostream& Player::operator<<(std::ostream &out) {
    return out << toString();
}
