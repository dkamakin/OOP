#ifndef NEWGAMECOMMAND_H
#define NEWGAMECOMMAND_H

#include "command.h"

using sNewGameCommand = std::shared_ptr <class NewGameCommand>;

class NewGameCommand : public Command {
public:
    explicit NewGameCommand(sGameController controller);
    void execute() override;
};

#endif // NEWGAMECOMMAND_H
