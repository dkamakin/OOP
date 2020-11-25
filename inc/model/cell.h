#ifndef CELL_H
#define CELL_H

#include <memory>
#include "celltype.h"
#include "gameobjects/gameobject.h"
#include "utilities/point2d.h"

using sCell = std::shared_ptr <class Cell>;
using ssCell = std::shared_ptr <sCell>;

class Cell {
    CELL_TYPE type_;
    Point2D coords_;
    sGameObject object_;

public:
    Cell() = default;
    Cell(CELL_TYPE t, Point2D c, sGameObject obj);

    Point2D getCoords();
    CELL_TYPE getType();
    sGameObject getObject();

    void setCoords(Point2D c);
    void setType(CELL_TYPE t);
    void setObject(sGameObject obj);
};

#endif // CELL_H
