#include "gameobjects/sword/swordobjectfactory.h"

sGameObject SwordObjectFactory::createObject() {
    return sGameObject(new SwordObject);
}
