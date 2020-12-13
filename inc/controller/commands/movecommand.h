#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "command.h"

using sMoveCommand = std::shared_ptr <class MoveCommand>;

class MoveCommand : public Command {
    Direction direction_;

public:
    MoveCommand(sGameController controller, Direction direction);
    void execute() override;
};

#endif // MOVECOMMAND_H
