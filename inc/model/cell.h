#ifndef CELL_H
#define CELL_H

#include <memory>
#include "celltype.h"
#include "gameobjects/gameobject.h"
#include "utilities/point2d.h"

using sCell = std::shared_ptr <class Cell>;
using ssCell = std::shared_ptr <sCell>;

class Cell {
    CellType type_;
    Point2D coords_;
    sGameObject object_;

public:
    Cell() = default;
    Cell(CellType type, Point2D coords, sGameObject object);

    Point2D getCoords();
    CellType getType();
    sGameObject getObject();

    void setCoords(Point2D coords);
    void setType(CellType type);
    void setObject(sGameObject object);
};

#endif // CELL_H
