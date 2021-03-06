#include "controller/commands/newgamecommand.h"

NewGameCommand::NewGameCommand(sGameController controller) : Command(controller) {}

void NewGameCommand::execute() {
    controller_->newGame();
}
