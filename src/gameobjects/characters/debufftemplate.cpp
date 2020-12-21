#include "gameobjects/characters/debufftemplate.h"

void DebuffTemplate::interact(Player &player, Character&) {
    player.setHealthDebuff(true);
}
