#include "gameobjects/player.h"

Player::Player(Point2D coords, size_t health, sInteractStrategy strategy) {
    setPoints(0);
    setCoords(coords);
    setHealth(health);
    setEnd(false);
    strategy_ = strategy;
}

std::string Player::toString() {
    return "Coords: " + getCoords().toString() + "\n" +
            "Points: " + std::to_string(getPoints()) + "\n" +
            "Health: " + std::to_string(getHealth()) + "\n" +
            "End: " + (getEnd() ? "true" : "false") + "\n";
}

void Player::setStrategy(sInteractStrategy strategy) {
    strategy_ = strategy;
}

void Player::operator+=(sGameObject &right) {
    if (!right || !strategy_)
        return;

    strategy_->interact(*this, right);
}

std::ostream& Player::operator<<(std::ostream &out) {
    return out << toString();
}
