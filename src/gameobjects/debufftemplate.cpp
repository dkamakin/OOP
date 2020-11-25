#include "inc/gameobjects/debufftemplate.h"

void DebuffTemplate::interact(Player &player) {
    player.setHealthDebuff(true);
}
