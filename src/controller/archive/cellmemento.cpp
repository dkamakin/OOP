#include "controller/archive/cellmemento.h"

CellMemento::CellMemento(Point2D coords, CellType type, ArchiveType object) : coords_(coords), type_(type), object_(object) {}

Point2D& CellMemento::getCoords() {
    return coords_;
}

CellType& CellMemento::getType() {
    return type_;
}

ArchiveType& CellMemento::getObject() {
    return object_;
}
