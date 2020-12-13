#include "gameobjects/coin/coinobjectfactory.h"

sGameObject CoinObjectFactory::createObject() {
    return sCoinObject(new CoinObject());
}
