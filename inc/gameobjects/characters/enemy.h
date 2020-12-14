#ifndef ENEMY_H
#define ENEMY_H

#include "enemytemplate.h"
#include "enemyabstract.h"
#include "controller/archive/enemymemento.h"

template <typename EnemyTemplate>
class Enemy : public EnemyAbstract {
    sEnemyTemplate template_;

public:
    Enemy(Point2D coords, int health) : template_(sEnemyTemplate(new EnemyTemplate)) {
        setCoords(coords);
        setHealth(health);
    }

    explicit Enemy(Character character) : template_(sEnemyTemplate(new EnemyTemplate)) {
        setCoords(character.getCoords());
        setHealth(character.getHealth());
    }

    const std::type_info& getTypeInfo() override {
        return typeid(Enemy<EnemyTemplate>);
    }

    void operator+=(Player &player) override {
        interact(player);
    }

    EnemyMemento save() {
        return EnemyMemento(*this);
    }

    ~Enemy() = default;

private:
    void interact(Player &player) override {
        template_->interact(player);
    }

};

#endif // ENEMY_H
