#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "command.h"

using sSaveCommand = std::shared_ptr <class SaveCommand>;

class SaveCommand : public Command {
public:
    explicit SaveCommand(sGameController controller);
    void execute() override;
};

#endif // SAVECOMMAND_H
