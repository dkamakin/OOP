#include "gameobjects/characters/attacktemplate.h"

void AttackTemplate::interact(Player &player) {
    player.decHealth(10);
}
