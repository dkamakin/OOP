#ifndef PLAYERMEMENTO_H
#define PLAYERMEMENTO_H

#include "gameobjects/characters/player.h"
#include "gameobjects/characters/interactstrategy.h"

class PlayerMemento {
    Character player_;
    size_t interactionType_;

public:
    PlayerMemento() = default;
    PlayerMemento(Character player, size_t type);

    size_t& getType();
    Character& getPlayer();
};

#endif // PLAYERMEMENTO_H
