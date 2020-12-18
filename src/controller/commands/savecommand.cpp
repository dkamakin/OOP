#include "controller/commands/savecommand.h"

SaveCommand::SaveCommand(sGameController controller, std::string file) : Command(controller), file_(file) {}

void SaveCommand::execute() {
    controller_->saveGame(file_);
}
