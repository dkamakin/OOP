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

PlayerMemento Player::save() {
    InteractionType type_ = GameInteractType;

    if (strategy_->getTypeInfo() == typeid (GameInteract))
        type_ = GameInteractType;

    return PlayerMemento(*this, type_);
}

void Player::restore(PlayerMemento &backup) {
    Character player = backup.getPlayer();
    InteractionType type = backup.getType();

    setCoords(player.getCoords());
    setHealth(player.getHealth());
    setHealthDebuff(player.getHealthDebuff());
    setPoints(player.getPoints());
    setEnd(player.getEnd());
    setDirection(player.getDirection());

    if (type == GameInteractType)
        setStrategy(sInteractStrategy(new GameInteract));
    else
        setStrategy(nullptr);
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
