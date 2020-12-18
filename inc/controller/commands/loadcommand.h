#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H

#include "command.h"

using sLoadCommand = std::shared_ptr <class LoadCommand>;

class LoadCommand : public Command {
    std::string file_;

public:
    LoadCommand(sGameController controller, std::string file);
    void execute() override;
};

#endif // LOADCOMMAND_H
