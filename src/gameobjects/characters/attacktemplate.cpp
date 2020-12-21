#include "gameobjects/characters/attacktemplate.h"

void AttackTemplate::interact(Player &player, Character &enemy) {
    player.decHealth(enemy.getDamageDeal());
}
