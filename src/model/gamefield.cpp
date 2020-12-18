#include "model/gamefield.h"

uGameField GameField::uniqueInstance_ = nullptr;

GameField& GameField::getInstance() {
    if (!uniqueInstance_)
        uniqueInstance_ = uGameField(new GameField());

    return *uniqueInstance_;
}

GameField& GameField::getInstance(Size2D size) {
    if (!uniqueInstance_)
        uniqueInstance_ = uGameField(new GameField(size));

    return *uniqueInstance_;
}

FieldMemento GameField::save() {
    vvCellMemento cells;
    cells.resize(getHeight());

    for (auto y = 0; y < getHeight(); y++) {
        cells[y].resize(getWidth());
        for (auto x = 0; x < getWidth(); x++)
            cells[y][x] = field_.get()[y].get()[x].save();
    }

    return FieldMemento(size_, cells);
}

void GameField::restore(FieldMemento &backup) {
    size_ = backup.getSize();
    setSize(size_);
    auto &field = backup.getField();

    for (auto y = 0; y < getHeight(); y++) {
        for (auto x = 0; x < getWidth(); x++)
            field_.get()[y].get()[x].restore(field[y][x]);
    }
}

void GameField::deleteInstance() {
    uniqueInstance_ = nullptr;
}

GameField::GameField() {
    field_ = nullptr;
}

GameField::GameField(Size2D size) : size_(size) {
    field_ = ssGameCell(new sGameCell[getHeight()], std::default_delete<sGameCell[]>());

    for (auto y = 0; y < getHeight(); y++)
        field_.get()[y] = sGameCell(new GameCell[getWidth()], std::default_delete<GameCell[]>());
}

int GameField::getHeight() {
    return size_.getX();
}

int GameField::getWidth() {
    return size_.getY();
}

Size2D GameField::getSize() {
    return size_;
}

void GameField::setCell(GameCell cell) {
    field_.get()[cell.getCoords().getY()].get()[cell.getCoords().getX()].getObject() = nullptr;
    field_.get()[cell.getCoords().getY()].get()[cell.getCoords().getX()] = cell;
}

void GameField::setObject(Point2D coords, sGameObject object) {
    field_.get()[coords.getY()].get()[coords.getX()].setObject(object);
}

GameField& GameField::operator=(const GameField &obj) {
    if (&obj == this)
        return *this;

    deleteField();
    size_ = obj.size_;

    field_ = ssGameCell(new sGameCell[getHeight()], std::default_delete<sGameCell[]>());

    for (auto y = 0; y < getHeight(); y++) {
        field_.get()[y] = sGameCell(new GameCell[getWidth()], std::default_delete<GameCell[]>());
        for (auto x = 0; x < getWidth(); x++) {
            field_.get()[y].get()[x] = obj.field_.get()[y].get()[x];
        }
    }

    return *this;
}

void GameField::setSize(Size2D size) {
    deleteField();
    size_ = size;
    field_ = ssGameCell(new sGameCell[getHeight()], std::default_delete<sGameCell[]>());

    for (auto y = 0; y < getHeight(); y++)
        field_.get()[y] = sGameCell(new GameCell[getWidth()], std::default_delete<GameCell[]>());
}

GameField::GameField(GameField &&obj) : size_(obj.size_), field_(obj.field_) {
    obj.field_ = nullptr;
}

GameField::GameField(GameField &obj) : size_(obj.size_) {
    field_ = ssGameCell(new sGameCell[getHeight()], std::default_delete<sGameCell[]>());

    for (auto y = 0; y < getHeight(); y++) {
        field_.get()[y] = sGameCell(new GameCell[getWidth()], std::default_delete<GameCell[]>());
        for (auto x = 0; x < getWidth(); x++) {
            field_.get()[y].get()[x] = obj.field_.get()[y].get()[x];
        }
    }
}

void GameField::deleteField() {
    field_ = nullptr;
}

GameCell& GameField::getCell(Point2D coords) {
    return field_.get()[coords.getY()].get()[coords.getX()];
}

CellType GameField::getType(Point2D coords) {
    return field_.get()[coords.getY()].get()[coords.getX()].getType();
}

sGameObject& GameField::getObject(Point2D coords) {
    return field_.get()[coords.getY()].get()[coords.getX()].getObject();
}

GameField::Iterator GameField::begin() {
    return GameField::Iterator(Point2D());
}

GameField::Iterator GameField::end() {
    return Iterator(Point2D(0, uniqueInstance_->getHeight()));
}

GameField::Iterator::Iterator(Point2D c): coords_(c) {}

bool GameField::Iterator::operator==(const Iterator& other) {
    return coords_ == other.coords_;
}

bool GameField::Iterator::operator!=(const Iterator& other) {
    return !operator==(other);
}

GameField::Iterator& GameField::Iterator::operator++() {
    if (coords_.getX() + 1 >= GameField::getInstance().getWidth()) {
        coords_.setY(coords_.getY() + 1);
        coords_.setX(0);
    } else
        coords_.setX(coords_.getX() + 1);

    return *this;
}

GameField::Iterator GameField::Iterator::operator++(int) {
    Iterator iterator(*this);
    operator++();
    return iterator;
}

GameCell& GameField::Iterator::operator*() {
    return GameField::getInstance().getCell(coords_);
}
