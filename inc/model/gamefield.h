#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <memory>
#include "gamecell.h"
#include "controller/archive/fieldmemento.h"

using uGameField = std::unique_ptr <class GameField>;

class GameField {
    static uGameField uniqueInstance_;

    Size2D size_;
    ssGameCell field_;

    class Iterator;

public:
    int getHeight();
    int getWidth();
    Size2D getSize();

    CellType getType(Point2D coords);
    sGameObject& getObject(Point2D coords);
    bool getPassable(Point2D coords);

    void setSize(Size2D size);
    void setCell(GameCell cell);
    void setObject(Point2D coords, sGameObject object);

    void restore(FieldMemento &backup);
    FieldMemento save();

    GameCell& getCell(Point2D coords);
    static GameField& getInstance(Size2D size);
    static GameField& getInstance();
    static void deleteInstance();

    Iterator begin();
    Iterator end();

private:
    GameField(GameField &obj);
    GameField(GameField &&obj);
    GameField& operator=(const GameField &obj);
    GameField();
    GameField(Size2D size);
    void deleteField();

};

class GameField::Iterator {
    Point2D coords_;

public:
    Iterator(Point2D coords);

    bool operator==(const Iterator &object);
    bool operator!=(const Iterator &object);
    Iterator& operator++();
    Iterator operator++(int);
    GameCell& operator*();
};

#endif // GAMEFIELD_H
