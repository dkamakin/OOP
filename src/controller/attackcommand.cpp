#include "inc/controller/attackcommand.h"

AttackCommand::AttackCommand(sGameController controller) : Command(controller) {}

void AttackCommand::execute() {
    controller_->playerAttack();
}
