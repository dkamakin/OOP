#ifndef COMMAND_H
#define COMMAND_H

#include "gamecontroller.h"

using sCommand = std::shared_ptr <class Command>;

class Command {
public:
    Command(sGameController controller);
    virtual void execute() = 0;
    ~Command() = default;

protected:
    sGameController controller_;
};

#endif // COMMAND_H
