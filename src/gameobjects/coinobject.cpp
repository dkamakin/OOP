#include "gameobjects/coinobject.h"

bool CoinObject::action(Character &character) {
    character.addPoints(1);
    return true;
}

bool CoinObject::isDisposable() {
    return true;
}

std::string CoinObject::toString() {
    return "Coin object";
}

const std::type_info& CoinObject::getTypeInfo() {
    return typeid(CoinObject);
}
