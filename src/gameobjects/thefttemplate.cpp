#include "inc/gameobjects/thefttemplate.h"

void TheftTemplate::interact(Player &player) {
    player.decPoints(1);
}
