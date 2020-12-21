#ifndef OBJECTSMAPPER_H
#define OBJECTSMAPPER_H

#include <QImage>
#include "model/celltype.h"
#include "gameobjects/gameobject.h"
#include "gameobjects/characters/enemyabstract.h"
#include "gameobjects/coin/coinobject.h"
#include "gameobjects/exit/exitobject.h"
#include "gameobjects/sword/swordobject.h"
#include "gameobjects/characters/thefttemplate.h"
#include "gameobjects/characters/debufftemplate.h"
#include "gameobjects/characters/attacktemplate.h"
#include "gameobjects/characters/enemy.h"

#define EXIT_IMAGE ":/resources/exit.png"
#define COIN_IMAGE ":/resources/coin.png"
#define WALL_IMAGE ":/resources/wall.png"
#define ENTER_IMAGE ":/resources/enter.png"
#define EMPTY_IMAGE ":/resources/empty.png"
#define PLAYER_IMAGE ":/resources/player.png"
#define BORDER_IMAGE ":/resources/border.png"
#define STATUE_IMAGE ":/resources/enemyStatue.png"
#define GIRL_IMAGE ":/resources/girl.png"
#define GHOST_IMAGE ":/resources/ghost.png"
#define SWORD_IMAGE ":/resources/sword.png"

using sObjectMapper = std::shared_ptr <class ObjectMapper>;

class ObjectMapper {
    int cellWidth_;
    int cellHeight_;

public:
    ObjectMapper(int width, int height);
    ~ObjectMapper() = default;

    void setHeight(int height);
    void setWidth(int width);
    int getHeight();
    int getWidth();

    QImage getImage(CellType type);
    QImage getImage(sGameObject object);
    QImage getImage(sEnemyAbstract enemy);
};

#endif // OBJECTSMAPPER_H
