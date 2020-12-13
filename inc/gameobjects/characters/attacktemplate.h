#ifndef ATTACKTEMPLATE_H
#define ATTACKTEMPLATE_H

#include "enemytemplate.h"
#include "player.h"

using sAttackTemplate = std::shared_ptr <class AttackTemplate>;

class AttackTemplate : public EnemyTemplate {
public:
    AttackTemplate() = default;
    void interact(Player &player) override;
};

#endif // ATTACKTEMPLATE_H
