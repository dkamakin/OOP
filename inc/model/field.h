#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include "gamefield.h"
#include "cell.h"
#include "gameobjects/coinobjectfactory.h"
#include "gameobjects/exitobjectfactory.h"

using sField = std::shared_ptr <class Field>;

class Field {
    GameField &field_;
    class Iterator;

public:
    Field(GameField &f);

    CellType getType(Point2D coords);
    sGameObject& getObject(Point2D coords);
    int getHeight();
    int getWidth();

    void makeMap();
    void deleteField();

    void setCell(Point2D coords, GameCell cell);
    void setObject(Point2D coords, sGameObject object);

    Iterator begin();
    Iterator end();
};

class Field::Iterator {
    Point2D coords_;
    Cell cell_;

public:
    Iterator(Point2D coords);

    bool operator==(const Iterator &object);
    bool operator!=(const Iterator &object);
    Iterator& operator++();
    Iterator operator++(int);
    Cell& operator*();
};

#endif // FIELD_H
