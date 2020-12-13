#ifndef GAMECELL_H
#define GAMECELL_H

#include <memory>
#include "utilities/point2d.h"
#include "gameobjects/gameobject.h"
#include "gameobjects/coin/coinobject.h"
#include "gameobjects/exit/exitobject.h"
#include "celltype.h"

using sGameCell = std::shared_ptr <class GameCell>;
using ssGameCell = std::shared_ptr <sGameCell>;

class GameCell {
    CellType type_;
    Point2D coords_;
    sGameObject object_;

public:
    GameCell() = default;
    GameCell(CellType type, Point2D point, sGameObject object);
    ~GameCell() = default;

    CellType getType();
    Point2D getCoords();
    sGameObject& getObject();

    void setType(CellType t);
    void setCoords(Point2D point);
    void setObject(sGameObject obj);
};

#endif // GAMECELL_H
