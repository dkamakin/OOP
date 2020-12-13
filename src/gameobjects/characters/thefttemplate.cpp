#include "gameobjects/characters/thefttemplate.h"

void TheftTemplate::interact(Player &player) {
    player.decPoints(1);
}
