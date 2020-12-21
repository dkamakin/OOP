#include "gameobjects/characters/thefttemplate.h"

void TheftTemplate::interact(Player &player, Character&) {
    player.decPoints(1);
}
