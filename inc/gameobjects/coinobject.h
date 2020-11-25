#ifndef COINOBJECT_H
#define COINOBJECT_H

#include "gameobject.h"

using sCoinObject = std::shared_ptr <class CoinObject>;

class CoinObject : public GameObject {
public:
    CoinObject() = default;
    bool action(Character &character) override;
    bool isDisposable() override;
    std::string toString() override;
    const std::type_info& getTypeInfo() override;
};

#endif // COINOBJECT_H
