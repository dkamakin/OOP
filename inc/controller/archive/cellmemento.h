#ifndef CELLMEMENTO_H
#define CELLMEMENTO_H

#include "utilities/point2d.h"
#include "gameobjects/gameobject.h"
#include "model/celltype.h"

class CellMemento {
    Point2D coords_;
    CellType type_;
    size_t object_;
    bool passable_;

public:
    CellMemento() = default;
    CellMemento(Point2D coords, CellType type, size_t object, bool passable);

    Point2D& getCoords();
    CellType& getType();
    size_t& getObject();
    bool& getPassable();
};

#endif // CELLMEMENTO_H
