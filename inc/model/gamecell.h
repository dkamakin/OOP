#ifndef GAMECELL_H
#define GAMECELL_H

#include <memory>
#include "utilities/point2d.h"
#include "gameobjects/gameobject.h"
#include "gameobjects/coinobject.h"
#include "gameobjects/exitobject.h"
#include "celltype.h"

using sGameCell = std::shared_ptr <class GameCell>;
using ssGameCell = std::shared_ptr <sGameCell>;

class GameCell {
    CELL_TYPE type_;
    Point2D coords_;
    sGameObject object_;

public:
    GameCell() = default;
    GameCell(CELL_TYPE type, Point2D point, sGameObject object);
    ~GameCell() = default;

    CELL_TYPE getType();
    Point2D getCoords();
    sGameObject& getObject();

    void setType(CELL_TYPE t);
    void setCoords(Point2D point);
    void setObject(sGameObject obj);
};

#endif // GAMECELL_H
