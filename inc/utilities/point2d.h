#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include "controller/direction.h"

class Point2D {
    int x_;
    int y_;

public:
    Point2D() = default;
    Point2D(int x, int y);

    int getX();
    int getY();
    void move(Direction direction);
    void setX(int value);
    void setY(int value);
    std::string toString();

    friend const Point2D operator+(const Point2D &left, const Point2D &right);
    friend Point2D& operator+=(Point2D &left, const Point2D &right);
    friend Point2D& operator-=(Point2D &left, const Point2D &right);
    bool operator==(const Point2D &other);
    bool operator!=(const Point2D &other);
};

#endif // POINT2D_H
