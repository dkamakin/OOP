#include "model/gamecell.h"

GameCell::GameCell(CellType type, Point2D coords, sGameObject object, bool passable) :
    type_(type), coords_(coords), object_(object), passable_(passable) {}

void GameCell::setType(CellType type) {
    type_ = type;
}

bool GameCell::getPassable() {
    return passable_;
}

sGameObject& GameCell::getObject() {
    return object_;
}

CellMemento GameCell::save() {
    if (!object_)
        return CellMemento(coords_, type_, 0, passable_);

    return CellMemento(coords_, type_, object_->getTypeInfo().hash_code(), passable_);
}

void GameCell::restore(CellMemento &backup) {
    setCoords(backup.getCoords());
    setType(backup.getType());
    setPassble(backup.getPassable());

    size_t &object = backup.getObject();

    if (object == typeid(CoinObject).hash_code()) {
        setObject(CoinObjectFactory().createObject());
    } else if (object == typeid(ExitObject).hash_code()) {
        setObject(ExitObjectFactory().createObject());
    } else if (object == typeid(SwordObject).hash_code()) {
        setObject(SwordObjectFactory().createObject());
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

void GameCell::setPassble(bool passable) {
    passable_ = passable;
}

void GameCell::setObject(sGameObject object) {
    object_ = object;
}
