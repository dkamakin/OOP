#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "characters/character.h"

class Player;

using sGameObject = std::shared_ptr <class GameObject>;

class GameObject {
public:
    virtual bool action(Character &character) = 0;
    virtual bool isDisposable() = 0;
    virtual std::string toString() = 0;
    virtual const std::type_info& getTypeInfo() = 0;
    virtual ~GameObject() = default;
};

#endif // GAMEOBJECT_H
