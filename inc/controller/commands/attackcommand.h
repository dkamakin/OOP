#ifndef ATTACKCOMMAND_H
#define ATTACKCOMMAND_H

#include "command.h"

using sAttackCommand = std::shared_ptr <class AttackCommand>;

class AttackCommand : public Command {
public:
    explicit AttackCommand(sGameController controller);
    void execute() override;
};

#endif // ATTACKCOMMAND_H
