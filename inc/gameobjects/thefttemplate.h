#ifndef THEFTTEMPLATE_H
#define THEFTTEMPLATE_H

#include "enemytemplate.h"

using sTheftTemplate = std::shared_ptr <class TheftTemplate>;

class TheftTemplate : public EnemyTemplate {
public:
    void interact(Player &player) override;
};

#endif // THEFTTEMPLATE_H
