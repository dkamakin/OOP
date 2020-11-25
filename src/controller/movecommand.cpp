#include "controller/movecommand.h"

MoveCommand::MoveCommand(sGameController controller, DIRECTION direction) : Command(controller), direction_(direction) {}

void MoveCommand::execute() {
    controller_->movePlayer(direction_);
}
