#ifndef ENEMYMEMENTO_H
#define ENEMYMEMENTO_H

#include "gameobjects/characters/character.h"
#include "controller/archive/archivetype.h"

class EnemyMemento {
    Character enemy_;

public:
    EnemyMemento() = default;
    EnemyMemento(Character enemy);

    Character getEnemy();
};

#endif // ENEMYMEMENTO_H
