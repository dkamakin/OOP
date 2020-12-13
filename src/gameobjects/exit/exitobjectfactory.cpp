#include "gameobjects/exit/exitobjectfactory.h"

sGameObject ExitObjectFactory::createObject() {
    return sExitObject(new ExitObject());
}
