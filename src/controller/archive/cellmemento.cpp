#include "controller/archive/cellmemento.h"

CellMemento::CellMemento(Point2D coords, CellType type, size_t object) : coords_(coords), type_(type), object_(object) {}

Point2D& CellMemento::getCoords() {
    return coords_;
}

CellType& CellMemento::getType() {
    return type_;
}

size_t& CellMemento::getObject() {
    return object_;
}
