#ifndef LOADER_H
#define LOADER_H

#include "controller/gamecontroller.h"
#include "archivetype.h"

using sLoader = std::shared_ptr <class Loader>;
using sGameController = std::shared_ptr <class GameController>;
using listEnemies = std::list <sEnemyAbstract>;

class Loader {
    std::ifstream input_;

public:
    Loader() = default;
    void execute(std::string fileName, sPlayer &player, listEnemies &enemies);

private:
    EnemyMemento loadEnemy();
    void loadField(FieldMemento &field);
    void loadPlayer(Player &player);
};

#endif // LOADER_H
