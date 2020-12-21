#ifndef SWORDOBJECT_H
#define SWORDOBJECT_H

#include "gameobjects/gameobject.h"

using sSwordObject = std::shared_ptr <class SwordObject>;

class SwordObject : public GameObject {
public:
    SwordObject() = default;
    bool action(Character &character) override;
    bool isDisposable() override;
    std::string toString() override;
    const std::type_info& getTypeInfo() override;
};

#endif // SWORDOBJECT_H
