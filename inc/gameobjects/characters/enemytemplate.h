#ifndef ENEMYTEMPLATE_H
#define ENEMYTEMPLATE_H

#include <memory>

class Player;
class Character;

using sEnemyTemplate = std::shared_ptr <class EnemyTemplate>;

class EnemyTemplate {
public:
    virtual void interact(Player &player, Character &enemy) = 0;
    virtual ~EnemyTemplate() = default;
};

#endif // ENEMYTEMPLATE_H
