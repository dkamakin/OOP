#ifndef INTERACTSTRATEGY_H
#define INTERACTSTRATEGY_H

#include <memory>
#include "player.h"
#include "gameobject.h"

using sInteractStrategy = std::shared_ptr <class InteractStrategy>;

class InteractStrategy {
public:
    virtual void interact(Character &character, sGameObject &object) = 0;
    ~InteractStrategy() = default;
};

#endif // INTERACTSTRATEGY_H
