#ifndef SAVER_H
#define SAVER_H

#include "controller/gamecontroller.h"

using sSaver = std::shared_ptr <class Saver>;
using sGameController = std::shared_ptr <class GameController>;
using listEnemies = std::list <sEnemyAbstract>;

class Saver {
    std::ofstream output_;

public:
    Saver() = default;
    void execute(std::string fileName, sPlayer player, listEnemies &enemies);

private:
    void savePlayer(Player &player);
    void saveField(GameField &field);
    void saveEnemy(sEnemyAbstract &enemy);
};

#endif // SAVER_H
