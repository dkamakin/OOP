#include "controller/archive/playermemento.h"

PlayerMemento::PlayerMemento(Character player, size_t type) : player_(player), interactionType_(type) {}

size_t& PlayerMemento::getType() {
    return interactionType_;
}

Character& PlayerMemento::getPlayer() {
    return player_;
}
