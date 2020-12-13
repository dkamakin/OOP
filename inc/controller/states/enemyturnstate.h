#ifndef ENEMYTURNSTATE_H
#define ENEMYTURNSTATE_H

#include "controllerstate.h"
#include "controller/gamecontroller.h"

using sEnemyTurnState = std::shared_ptr <class EnemyTurnState>;

class EnemyTurnState : public ControllerState {
public:
    void moveCharacter(GameController& controller, Direction direction) override;
    void startTurn(GameController& controller) override;
    void endTurn(GameController& controller) override;
    void playerInteract(GameController &controller) override;
};

#endif // ENEMYTURNSTATE_H
