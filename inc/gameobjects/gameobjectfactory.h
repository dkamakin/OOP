#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "gameobject.h"

using sGameObjectFactory = std::shared_ptr <class GameObjectFactory>;

class GameObjectFactory {
public:
    virtual sGameObject createObject() = 0;
    ~GameObjectFactory() = default;
};

#endif // GAMEOBJECTFACTORY_H
