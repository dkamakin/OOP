#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "model/field.h"
#include "gameobjects/player.h"
#include "logger/loggercontext.h"
#include "controller/direction.h"
#include "gameobjects/enemy.h"
#include "gameobjects/thefttemplate.h"
#include "gameobjects/attacktemplate.h"
#include "gameobjects/debufftemplate.h"
#include "controllerstate.h"
#include "playerturnstate.h"
#include "enemyturnstate.h"
#include <list>

using sGameController = std::shared_ptr <class GameController>;
using listEnemies = std::list<sEnemyAbstract>;

class GameController {
    sField field_;
    sPlayer player_;
    sControllerState state_;
    listEnemies enemies_;

public:
    GameController(sField object, sControllerState state);
    ~GameController();

    void newGame();
    void endGame();
    void playerAttack();

    void setTurn(sControllerState state);
    void move(Direction direction);
    void startTurn();

    Point2D getPlayerCoords();
    std::string getPlayerInfo();
    sField getField();
    sPlayer& getPlayer();
    listEnemies& getEnemies();
    size_t getPoints();
    size_t getPlayerHealth();
    sEnemyAbstract getEnemy(Point2D coords);
    CellType getType(Point2D &coords);

    bool isEnemy(Point2D coords);
    bool isEnd();
};

#endif // GAMECONTROLLER_H
