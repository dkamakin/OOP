#include "gameobjects/characters/player.h"

Player::Player(Point2D coords, size_t health, sInteractStrategy strategy, int damageDeal) {
    setPoints(0);
    setCoords(coords);
    setHealth(health);
    setHealthDebuff(false);
    setEnd(false);
    setDirection(Right);
    setDamageDeal(damageDeal);
    strategy_ = strategy;
}

void Player::setStrategy(sInteractStrategy strategy) {
    strategy_ = strategy;
}

PlayerMemento Player::save() {
    if (!strategy_)
        return PlayerMemento(*this, 0);

    return PlayerMemento(*this, strategy_->getTypeInfo().hash_code());
}

void Player::restore(PlayerMemento &backup) {
    Character player = backup.getPlayer();
    size_t type = backup.getType();

    setCoords(player.getCoords());
    setHealth(player.getHealth());
    setHealthDebuff(player.getHealthDebuff());
    setPoints(player.getPoints());
    setEnd(player.getEnd());
    setDirection(player.getDirection());
    addDamageDeal(player.getDamageDeal());

    if (type == typeid(GameInteract).hash_code())
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

    right->decHealth(getDamageDeal());
}

std::ostream& Player::operator<<(std::ostream &out) {
    return out << toString();
}
