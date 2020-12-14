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
        return CellMemento(coords_, type_, NullType);

    auto &type = object_->getTypeInfo();
    if (type == typeid (CoinObject)) {
        return CellMemento(coords_, type_, CoinType);
    } else if (type == typeid (ExitObject)) {
        return CellMemento(coords_, type_, ExitType);
    }

    return CellMemento(coords_, type_, NullType);
}

void GameCell::restore(CellMemento &backup) {
    setCoords(backup.getCoords());
    setType(backup.getType());

    switch (backup.getObject()) {
        case CoinType:
            setObject(CoinObjectFactory().createObject());
            break;
        case ExitType:
            setObject(ExitObjectFactory().createObject());
            break;
        case NullType:
        default:
            setObject(nullptr);
        break;
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
