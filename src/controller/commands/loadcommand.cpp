#include "controller/commands/loadcommand.h"

LoadCommand::LoadCommand(sGameController controller) : Command(controller) {}

void LoadCommand::execute() {
    controller_->loadGame();
}