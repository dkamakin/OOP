#ifndef ENEMYMEMENTO_H
#define ENEMYMEMENTO_H

#include "gameobjects/characters/character.h"

class EnemyMemento {
    Character enemy_;

public:
    EnemyMemento() = default;
    explicit EnemyMemento(Character enemy);

    Character& getEnemy();
};

#endif // ENEMYMEMENTO_H
