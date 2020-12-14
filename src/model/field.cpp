#include "model/field.h"

Field::Field(GameField &field) : field_(field) {}

CellType Field::getType(Point2D coords) {
    return field_.getType(coords);
}

sGameObject& Field::getObject(Point2D coords) {
    return field_.getObject(coords);
}

void Field::setCell(Point2D coords, GameCell cell) {
    field_.setCell(coords, cell);
}

void Field::setObject(Point2D coords, sGameObject object) {
    field_.setObject(coords, object);
}

void Field::makeMap() {
    field_.setSize(Size2D(1, 1));
}

void Field::deleteField() {
    field_.deleteInstance();
}

int Field::getHeight() {
    return field_.getHeight();
}

int Field::getWidth() {
    return field_.getWidth();
}

Size2D Field::getSize() {
    return field_.getSize();
}

Field::Iterator Field::begin() {
    return Field::Iterator(Point2D());
}

Field::Iterator Field::end() {
    return Iterator(Point2D(0, getHeight()));
}

Field::Iterator::Iterator(Point2D c): coords_(c) {}

bool Field::Iterator::operator==(const Iterator& other) {
    return coords_ == other.coords_;
}

bool Field::Iterator::operator!=(const Iterator& other) {
    return !operator==(other);
}

Field::Iterator& Field::Iterator::operator++() {
    if (coords_.getX() + 1 >= GameField::getInstance().getWidth()) {
        coords_.setY(coords_.getY() + 1);
        coords_.setX(0);
    } else
        coords_.setX(coords_.getX() + 1);

    return *this;
}

Field::Iterator Field::Iterator::operator++(int) {
    Iterator iterator(*this);
    operator++();
    return iterator;
}

Cell& Field::Iterator::operator*() {
    auto &gameField = GameField::getInstance();
    cell_ = Cell(gameField.getType(coords_), coords_, gameField.getObject(coords_));
    return cell_;
}
