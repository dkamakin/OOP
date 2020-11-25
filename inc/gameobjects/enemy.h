#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "enemytemplate.h"

template <typename EnemyTemplate>
class Enemy : public Character {
    sEnemyTemplate template_;

public:
    Enemy() : template_(sEnemyTemplate(new EnemyTemplate)) {}

    void interact(Player &player) {
        template_->interact(player);
    }
};

#endif // ENEMY_H
