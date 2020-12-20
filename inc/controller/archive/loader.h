#ifndef LOADER_H
#define LOADER_H

#include <cstring>
#include "controller/gamecontroller.h"
#include "fieldstructure.h"
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
    void loadEnemy(EnemyMemento &enemy);
    void loadField(FieldMemento &field);
    void loadPlayer(PlayerMemento &player);
};

#endif // LOADER_H
