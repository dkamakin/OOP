#ifndef NEXTLEVELCOMMAND_H
#define NEXTLEVELCOMMAND_H

#include "command.h"

using sNextLevelCommand = std::shared_ptr <class NextLevelCommand>;

class NextLevelCommand : public Command {
public:
    NextLevelCommand(sGameController);
    void execute() override;
};

#endif // NEXTLEVELCOMMAND_H
