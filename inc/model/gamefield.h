#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <memory>
#include "gamecell.h"

using uGameField = std::unique_ptr <class GameField>;

class GameField {
    static uGameField uniqueInstance_;

    int height_;
    int width_;
    ssGameCell field_;

    class Iterator;

public:
    int getHeight();
    int getWidth();
    CellType getType(Point2D coords);
    sGameObject& getObject(Point2D coords);

    void setSize(int rows, int cols);
    void setCell(Point2D coords, GameCell cell);
    void setObject(Point2D coords, sGameObject object);

    GameCell& getCell(Point2D coords);
    static GameField& getInstance(int rows, int cols);
    static GameField& getInstance();
    static void deleteInstance();

    Iterator begin();
    Iterator end();

private:
    GameField(GameField &obj);
    GameField(GameField &&obj);
    GameField& operator=(const GameField &obj);
    GameField();
    GameField(int rows, int cols);
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
