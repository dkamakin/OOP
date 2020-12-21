#include "gameobjects/sword/swordobject.h"

bool SwordObject::action(Character &character) {
    character.addDamageDeal(10);
    return true;
}

bool SwordObject::isDisposable() {
    return true;
}

std::string SwordObject::toString() {
    return "Sword object";
}

const std::type_info& SwordObject::getTypeInfo() {
    return typeid(SwordObject);
}
