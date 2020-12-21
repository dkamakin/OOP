#ifndef THEFTTEMPLATE_H
#define THEFTTEMPLATE_H

#include "enemytemplate.h"
#include "player.h"

using sTheftTemplate = std::shared_ptr <class TheftTemplate>;

class TheftTemplate : public EnemyTemplate {
public:
    TheftTemplate() = default;
    void interact(Player &player, Character &enemy) override;
};

#endif // THEFTTEMPLATE_H
