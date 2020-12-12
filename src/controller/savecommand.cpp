#include "controller/savecommand.h"

SaveCommand::SaveCommand(sGameController controller) : Command(controller) {}

void SaveCommand::execute() {
    controller_->saveGame();
}
