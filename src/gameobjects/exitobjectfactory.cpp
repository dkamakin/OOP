#include "gameobjects/exitobjectfactory.h"

sGameObject ExitObjectFactory::createObject() {
    return sExitObject(new ExitObject());
}
