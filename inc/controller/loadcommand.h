#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H

#include "command.h"

using sLoadCommand = std::shared_ptr <class LoadCommand>;

class LoadCommand : public Command {
public:
    LoadCommand(sGameController controller);
    void execute() override;
};

#endif // LOADCOMMAND_H
