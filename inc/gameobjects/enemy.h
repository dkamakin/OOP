#ifndef ENEMY_H
#define ENEMY_H

#include "enemytemplate.h"
#include "enemyabstract.h"

template <typename EnemyTemplate>
class Enemy : public EnemyAbstract {
    sEnemyTemplate template_;

public:
    Enemy(Point2D coords, int health) : template_(sEnemyTemplate(new EnemyTemplate)) {
        setCoords(coords);
        setHealth(health);
    }

    const std::type_info& getTypeInfo() override {
        return typeid(Enemy<EnemyTemplate>);
    }

    void operator+=(Player &player) override {
        interact(player);
    }

    ~Enemy() = default;

private:
    void interact(Player &player) override {
        template_->interact(player);
    }

};

#endif // ENEMY_H
