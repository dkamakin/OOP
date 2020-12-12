#ifndef CONTROLLERSTATE_H
#define CONTROLLERSTATE_H

#include <memory>
#include "direction.h"

using sControllerState = std::shared_ptr <class ControllerState>;
class GameController;

class ControllerState {
public:
    virtual void moveCharacter(GameController &controller, Direction direction) = 0;
    virtual void startTurn(GameController &controller) = 0;
    virtual void endTurn(GameController &controller) = 0;
    virtual void playerInteract(GameController &controller) = 0;
    ~ControllerState() = default;
};

#endif // CONTROLLERSTATE_H
