#include "model/gamecell.h"

GameCell::GameCell(CellType type, Point2D coords, sGameObject object) : type_(type), coords_(coords), object_(object) {}

void GameCell::setType(CellType type) {
    type_ = type;
}

sGameObject& GameCell::getObject() {
    return object_;
}

CellMemento GameCell::save() {
    if (!object_)
        return CellMemento(coords_, type_, 0);

    return CellMemento(coords_, type_, object_->getTypeInfo().hash_code());
}

void GameCell::restore(CellMemento &backup) {
    setCoords(backup.getCoords());
    setType(backup.getType());

    size_t &object = backup.getObject();

    if (object == typeid(CoinObject).hash_code()) {
        setObject(CoinObjectFactory().createObject());
    } else if (object == typeid(ExitObject).hash_code()) {
        setObject(ExitObjectFactory().createObject());
    } else {
        setObject(nullptr);
    }
}

CellType GameCell::getType() {
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
