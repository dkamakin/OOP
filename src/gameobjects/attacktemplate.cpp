#include "inc/gameobjects/attacktemplate.h"

void AttackTemplate::interact(Player &player) {
    player.decHealth(10);
}
