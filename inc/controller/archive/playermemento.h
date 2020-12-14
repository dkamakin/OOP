#ifndef PLAYERMEMENTO_H
#define PLAYERMEMENTO_H

#include "gameobjects/characters/player.h"
#include "gameobjects/characters/interactstrategy.h"

class PlayerMemento {
    Character player_;
    InteractionType type_;

public:
    PlayerMemento() = default;
    PlayerMemento(Character player, InteractionType type);

    InteractionType getType();
    Character getPlayer();
};

#endif // PLAYERMEMENTO_H
