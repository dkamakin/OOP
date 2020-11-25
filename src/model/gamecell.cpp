#include "model/gamecell.h"

GameCell::GameCell(CELL_TYPE type, Point2D coords, sGameObject object) : type_(type), coords_(coords), object_(object) {}

void GameCell::setType(CELL_TYPE type) {
    type_ = type;
}

sGameObject& GameCell::getObject() {
    return object_;
}

CELL_TYPE GameCell::getType() {
    return type_;
}

Point2D GameCell::getCoords() {
    return coords_;
}

void GameCell::setCoords(Point2D point) {
    coords_ = point;
}

void GameCell::setObject(sGameObject object) {
    object_ = object;
}
