#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "command.h"

using sMoveCommand = std::shared_ptr <class MoveCommand>;

class MoveCommand : public Command {
    DIRECTION direction_;

public:
    MoveCommand(sGameController controller, DIRECTION direction);
    void execute() override;
    ~MoveCommand() = default;
};

#endif // MOVECOMMAND_H
