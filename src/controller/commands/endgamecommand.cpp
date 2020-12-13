#include "controller/commands/endgamecommand.h"

EndGameCommand::EndGameCommand(sGameController controller) : Command(controller) {}

void EndGameCommand::execute() {
    controller_->endGame();
}
