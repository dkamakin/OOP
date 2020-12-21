#include "controller/archive/cellmemento.h"

CellMemento::CellMemento(Point2D coords, CellType type, size_t object, bool passable) :
    coords_(coords), type_(type), object_(object), passable_(passable) {}

Point2D& CellMemento::getCoords() {
    return coords_;
}

CellType& CellMemento::getType() {
    return type_;
}

size_t& CellMemento::getObject() {
    return object_;
}

bool& CellMemento::getPassable() {
    return passable_;
}
