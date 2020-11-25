#include "gameobjects/exitobject.h"

bool ExitObject::action(Character &character) {
    character.setEnd(true);
    return true;
}

bool ExitObject::isDisposable() {
    return false;
}

std::string ExitObject::toString() {
    return "Exit object";
}

const std::type_info& ExitObject::getTypeInfo() {
    return typeid(ExitObject);
}
