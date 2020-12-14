#include "controller/archive/enemymemento.h"

EnemyMemento::EnemyMemento(Character enemy) : enemy_(enemy) {}

Character EnemyMemento::getEnemy() {
    return enemy_;
}
