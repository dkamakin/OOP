#include "controller/archive/playermemento.h"

PlayerMemento::PlayerMemento(Character player, InteractionType type) : player_(player), type_(type) {}

InteractionType PlayerMemento::getType() {
    return type_;
}

Character PlayerMemento::getPlayer() {
    return player_;
}
