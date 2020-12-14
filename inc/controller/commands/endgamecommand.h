#ifndef ENDGAMECOMMAND_H
#define ENDGAMECOMMAND_H

#include "command.h"

using sEndGameCommand = std::shared_ptr <class EndGameCommand>;

class EndGameCommand : public Command {
public:
    explicit EndGameCommand(sGameController controller);
    void execute() override;
};

#endif // ENDGAMECOMMAND_H
