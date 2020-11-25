#ifndef EXITOBJECTFACTORY_H
#define EXITOBJECTFACTORY_H

#include "gameobjectfactory.h"
#include "exitobject.h"

using sExitObjectFactory = std::shared_ptr <class ExitObjectFactory>;

class ExitObjectFactory : public GameObjectFactory {
public:
    ExitObjectFactory() = default;
    sGameObject createObject() override;
};

#endif // EXITOBJECTFACTORY_H
