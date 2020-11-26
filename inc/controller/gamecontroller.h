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
#include <vector>

using sGameController = std::shared_ptr <class GameController>;

class GameController {
    sField field_;
    sPlayer player_;
    size_t moveCount_;
    std::vector<sEnemyAbstract> enemies_;

public:
    GameController(sField object, sPlayer player);
    ~GameController();

    void movePlayer(DIRECTION direction);
    void newGame();
    void endGame();

    Point2D getPlayerCoords();
    size_t getPoints();
    sField getField();
    std::vector<sEnemyAbstract>& getEnemies();
    bool isEnemyOnPoint(Point2D coords);
    size_t getPlayerHealth();
    CELL_TYPE getType(Point2D &coords);
    bool isEnd();
};

#endif // GAMECONTROLLER_H
