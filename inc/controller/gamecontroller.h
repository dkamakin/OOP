#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <list>
#include "model/fieldmapper.h"
#include "logger/loggercontext.h"
#include "gameobjects/characters/player.h"
#include "gameobjects/characters/enemy.h"
#include "gameobjects/characters/thefttemplate.h"
#include "gameobjects/characters/attacktemplate.h"
#include "gameobjects/characters/debufftemplate.h"
#include "archive/saver.h"
#include "archive/loader.h"
#include "states/controllerstate.h"
#include "states/playerturnstate.h"
#include "states/enemyturnstate.h"
#include "exceptions/archiveexception.h"

#define QUICK_FILE "../save.oop"

using sGameController = std::shared_ptr <class GameController>;
using listEnemies = std::list <sEnemyAbstract>;

class GameController {
    GameField &field_;
    sPlayer player_;
    sControllerState state_;
    listEnemies enemies_;

public:
    GameController(GameField &field, sControllerState state);
    ~GameController();

    void newGame();
    void endGame();

    void loadGame(std::string file);
    void saveGame(std::string file);

    void playerAttack();

    void setTurn(sControllerState state);
    void startTurn();
    void move(Direction direction);

    Point2D getPlayerCoords();
    std::string getPlayerInfo();
    sPlayer& getPlayer();
    listEnemies& getEnemies();
    sEnemyAbstract getEnemy(Point2D coords);
    GameField& getField();

    bool isEnemy(Point2D coords);
    bool isOver();
};

#endif // GAMECONTROLLER_H
