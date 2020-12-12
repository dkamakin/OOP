#include "utilities/point2d.h"

Point2D::Point2D(int x, int y) : x_(x), y_(y) {}

void Point2D::move(Direction direction) {
    switch (direction) {
        case Up:
            *this += Point2D(0, -1);
            break;
        case Left:
            *this += Point2D(-1, 0);
            break;
        case Down:
            *this += Point2D(0, 1);
            break;
        case Right:
            *this += Point2D(1, 0);
            break;
        default:
            break;
    }
}

Point2D operator+(Point2D &left, Point2D &right) {
    return Point2D(left.getX() + right.getX(), left.getY() + right.getY());
}

bool Point2D::operator==(const Point2D &other) {
    return x_ == other.x_ && y_ == other.y_;
}

bool Point2D::operator!=(const Point2D &other) {
    return !operator==(other);
}

Point2D& operator+=(Point2D &left, const Point2D &right) {
    left.x_ += right.x_;
    left.y_ += right.y_;
    return left;
}

Point2D& operator-=(Point2D &left, const Point2D &right) {
    left.x_ -= right.x_;
    left.y_ -= right.y_;
    return left;
}

std::string Point2D::toString() {
    return '(' + std::to_string(x_) + ',' + std::to_string(y_) + ')';
}

int Point2D::getX() {
    return x_;
}

int Point2D::getY() {
    return y_;
}

void Point2D::setX(int value) {
    x_ = value;
}

void Point2D::setY(int value) {
    y_ = value;
}
