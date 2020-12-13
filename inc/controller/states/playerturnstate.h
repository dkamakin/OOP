#ifndef PLAYERTURNSTATE_H
#define PLAYERTURNSTATE_H

#include "controllerstate.h"
#include "logger/loggercontext.h"
#include "enemyturnstate.h"
#include "controller/gamecontroller.h"

using sPlayerTurnState = std::shared_ptr <class PlayerTurnState>;

class PlayerTurnState : public ControllerState {
public:
    void moveCharacter(GameController& controller, Direction direction) override;
    void startTurn(GameController& controller) override;
    void endTurn(GameController& controller) override;
    void playerInteract(GameController &controller) override;
};

#endif // PLAYERTURNSTATE_H
