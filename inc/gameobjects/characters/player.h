#ifndef PLAYER_H
#define PLAYER_H

#include "gameobjects/gameobject.h"
#include "gameobjects/gameinteract.h"
#include "controller/archive/playermemento.h"
#include "interactstrategy.h"
#include "character.h"
#include "enemyabstract.h"

class GameObject;
class PlayerMemento;

using sPlayer = std::shared_ptr <class Player>;
using sInteractStrategy = std::shared_ptr <class InteractStrategy>;

class Player : public Character {
    sInteractStrategy strategy_;

public:
    Player(Point2D coords, size_t health, sInteractStrategy strategy);

    std::ostream& operator<<(std::ostream &out);
    void operator+=(sGameObject &right);
    void operator+=(sEnemyAbstract &right);

    void setStrategy(sInteractStrategy strategy);

    PlayerMemento save();
    void restore(PlayerMemento &backup);
};

#endif // PLAYER_H
