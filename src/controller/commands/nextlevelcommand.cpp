#include "controller/commands/nextlevelcommand.h"

NextLevelCommand::NextLevelCommand(sGameController controller) : Command(controller) {}

void NextLevelCommand::execute() {
    controller_->nextLevel();
}
