#include "model/cell.h"

Cell::Cell(CellType type, Point2D coords, sGameObject object) : type_(type), coords_(coords), object_(object) {}

Point2D Cell::getCoords() {
    return coords_;
}

CellType Cell::getType() {
    return type_;
}

sGameObject Cell::getObject(){
    return object_;
}

void Cell::setCoords(Point2D coords) {
    coords_ = coords;
}

void Cell::setType(CellType type) {
    type_ = type;
}

void Cell::setObject(sGameObject object) {
    object_ = object;
}
