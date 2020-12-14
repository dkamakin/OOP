#include "controller/commands/savecommand.h"

SaveCommand::SaveCommand(sGameController controller) : Command(controller) {}

void SaveCommand::execute() {
    controller_->saveGame();
}
