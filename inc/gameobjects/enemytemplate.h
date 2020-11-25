#ifndef ENEMYTEMPLATE_H
#define ENEMYTEMPLATE_H

#include <memory>
#include "player.h"

using sEnemyTemplate = std::shared_ptr <class EnemyTemplate>;

class EnemyTemplate {
public:
    virtual void interact(Player &player) = 0;
    ~EnemyTemplate() = default;
};

#endif // ENEMYTEMPLATE_H
