#ifndef ENEMYABSTRACT_H
#define ENEMYABSTRACT_H

#include "character.h"

class Player;

using sEnemyAbstract = std::shared_ptr <class EnemyAbstract>;

class EnemyAbstract : public Character {
public:
    virtual void interact(Player &player) = 0;
    virtual const std::type_info& getTypeInfo() = 0;
    virtual ~EnemyAbstract() = default;
};

#endif // ENEMYABSTRACT_H