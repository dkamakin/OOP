#include "model/gamefield.h"

uGameField GameField::uniqueInstance_ = nullptr;

GameField& GameField::getInstance() {
    if (!uniqueInstance_)
        uniqueInstance_ = uGameField(new GameField());

    return *uniqueInstance_;
}

GameField& GameField::getInstance(int rows, int cols) {
    if (!uniqueInstance_)
        uniqueInstance_ = uGameField(new GameField(rows, cols));

    return *uniqueInstance_;
}

void GameField::deleteInstance() {
    uniqueInstance_ = nullptr;
}

GameField::GameField() {
    field_ = nullptr;
}

GameField::GameField(int rows, int cols) : height_(rows), width_(cols) {
    field_ = ssGameCell(new sGameCell[height_], std::default_delete<sGameCell[]>());

    for (auto y = 0; y < rows; y++)
        field_.get()[y] = sGameCell(new GameCell[width_], std::default_delete<GameCell[]>());
}

int GameField::getHeight() {
    return height_;
}

int GameField::getWidth() {
    return width_;
}

void GameField::setCell(Point2D coords, GameCell cell) {
    field_.get()[coords.getY()].get()[coords.getX()].getObject() = nullptr;
    field_.get()[coords.getY()].get()[coords.getX()] = cell;
}

void GameField::setObject(Point2D coords, sGameObject object) {
    field_.get()[coords.getY()].get()[coords.getX()].setObject(object);
}

GameField& GameField::operator=(const GameField &obj) {
    if (&obj == this)
        return *this;

    deleteField();
    height_ = obj.height_;
    width_ = obj.width_;

    field_ = ssGameCell(new sGameCell[height_], std::default_delete<sGameCell[]>());

    for (auto y = 0; y < height_; y++) {
        field_.get()[y] = sGameCell(new GameCell[width_], std::default_delete<GameCell[]>());
        for (auto x = 0; x < width_; x++) {
            field_.get()[y].get()[x] = obj.field_.get()[y].get()[x];
        }
    }

    return *this;
}

void GameField::setSize(int height, int width) {
    deleteField();
    height_ = height;
    width_ = width;
    field_ = ssGameCell(new sGameCell[height_], std::default_delete<sGameCell[]>());

    for (auto y = 0; y < height_; y++)
        field_.get()[y] = sGameCell(new GameCell[width_], std::default_delete<GameCell[]>());
}

GameField::GameField(GameField &&obj) : height_(obj.height_), width_(obj.width_),
                                         field_(obj.field_) {
    obj.field_ = nullptr;
    obj.height_ = 0;
    obj.width_ = 0;
}

GameField::GameField(GameField &obj) : height_(obj.height_), width_(obj.width_) {
    field_ = ssGameCell(new sGameCell[height_], std::default_delete<sGameCell[]>());

    for (auto y = 0; y < height_; y++) {
        field_.get()[y] = sGameCell(new GameCell[width_], std::default_delete<GameCell[]>());
        for (auto x = 0; x < width_; x++) {
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
    return Iterator(Point2D(0, uniqueInstance_->height_));
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
