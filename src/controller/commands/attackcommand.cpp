#include "controller/commands/attackcommand.h"

AttackCommand::AttackCommand(sGameController controller) : Command(controller) {}

void AttackCommand::execute() {
    controller_->playerAttack();
}
