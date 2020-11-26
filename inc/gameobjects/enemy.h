#ifndef ENEMY_H
#define ENEMY_H

#include "enemytemplate.h"
#include "enemyabstract.h"

template <typename EnemyTemplate>
class Enemy : public EnemyAbstract {
    sEnemyTemplate template_;

public:
    Enemy(Point2D coords) : template_(sEnemyTemplate(new EnemyTemplate)) {
        setCoords(coords);
    }

    void interact(Player &player) override {
        template_->interact(player);
    }

    const std::type_info& getTypeInfo() {
        return typeid(Enemy<EnemyTemplate>);
    }

    ~Enemy() = default;
};

#endif // ENEMY_H
