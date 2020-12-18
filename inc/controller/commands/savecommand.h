#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "command.h"

using sSaveCommand = std::shared_ptr <class SaveCommand>;

class SaveCommand : public Command {
    std::string file_;

public:
    SaveCommand(sGameController controller, std::string file);
    void execute() override;
};

#endif // SAVECOMMAND_H
