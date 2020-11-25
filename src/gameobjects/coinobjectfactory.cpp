#include "gameobjects/coinobjectfactory.h"

sGameObject CoinObjectFactory::createObject() {
    return sCoinObject(new CoinObject());
}
