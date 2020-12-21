#ifndef SWORDOBJECTFACTORY_H
#define SWORDOBJECTFACTORY_H

#include "gameobjects/gameobjectfactory.h"
#include "swordobject.h"

using sSwordObjectFactory = std::shared_ptr <class SwordObjectFactory>;

class SwordObjectFactory : public GameObjectFactory {
public:
    SwordObjectFactory() = default;
    sGameObject createObject() override;
};

#endif // SWORDOBJECTFACTORY_H
