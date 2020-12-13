#ifndef EXITOBJECT_H
#define EXITOBJECT_H

#include "gameobjects/gameobject.h"

using sExitObject = std::shared_ptr <class ExitObject>;

class ExitObject : public GameObject {
public:
    ExitObject() = default;
    bool action(Character &character) override;
    bool isDisposable() override;
    std::string toString() override;
    const std::type_info& getTypeInfo() override;
};

#endif // EXITOBJECT_H
