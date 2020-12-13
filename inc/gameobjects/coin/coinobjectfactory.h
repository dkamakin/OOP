#ifndef COINOBJECTFACTORY_H
#define COINOBJECTFACTORY_H

#include "gameobjects/gameobjectfactory.h"
#include "coinobject.h"

using sCoinObjectFactory = std::shared_ptr <class CoinObjectFactory>;

class CoinObjectFactory : public GameObjectFactory {
public:
    CoinObjectFactory() = default;
    sGameObject createObject() override;
};

#endif // COINOBJECTFACTORY_H
