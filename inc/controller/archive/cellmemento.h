#ifndef CELLMEMENTO_H
#define CELLMEMENTO_H

#include "utilities/point2d.h"
#include "gameobjects/gameobject.h"
#include "model/celltype.h"
#include "archivetype.h"

class CellMemento {
    Point2D coords_;
    CellType type_;
    ArchiveType object_;

public:
    CellMemento() = default;
    CellMemento(Point2D coords, CellType type, ArchiveType object);

    Point2D& getCoords();
    CellType& getType();
    ArchiveType& getObject();
};

#endif // CELLMEMENTO_H
