#include "controller/movecommand.h"

MoveCommand::MoveCommand(sGameController controller, Direction direction) : Command(controller), direction_(direction) {}

void MoveCommand::execute() {
    controller_->move(direction_);
}
