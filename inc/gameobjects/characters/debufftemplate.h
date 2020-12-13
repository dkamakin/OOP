#ifndef DEBUFFTEMPLATE_H
#define DEBUFFTEMPLATE_H

#include "enemytemplate.h"
#include "player.h"

using sDebuffTemplate = std::shared_ptr <class DebuffTemplate>;

class DebuffTemplate : public EnemyTemplate {
public:
    DebuffTemplate() = default;
    void interact(Player &player) override;
};

#endif // DEBUFFTEMPLATE_H
