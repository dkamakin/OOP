#ifndef INTERACTSTRATEGY_H
#define INTERACTSTRATEGY_H

#include "gameobjects/gameobject.h"

using sInteractStrategy = std::shared_ptr <class InteractStrategy>;

class InteractStrategy {
public:
    virtual void interact(Character &character, sGameObject &object) = 0;
    virtual const std::type_info& getTypeInfo() = 0;
    ~InteractStrategy() = default;
};

#endif // INTERACTSTRATEGY_H
