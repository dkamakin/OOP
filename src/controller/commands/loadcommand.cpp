#include "controller/commands/loadcommand.h"

LoadCommand::LoadCommand(sGameController controller, std::string file) : Command(controller), file_(file) {}

void LoadCommand::execute() {
    controller_->loadGame(file_);
}
