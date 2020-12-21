#include "view/objectmapper.h"

ObjectMapper::ObjectMapper(int width, int height) : cellWidth_(width), cellHeight_(height) {}

int ObjectMapper::getHeight() {
    return cellHeight_;
}

int ObjectMapper::getWidth() {
    return cellWidth_;
}

void ObjectMapper::setHeight(int height) {
    cellHeight_ = height;
}

void ObjectMapper::setWidth(int width) {
    cellWidth_ = width;
}

QImage ObjectMapper::getImage(CellType type) {
    switch (type) {
        case Empty:
            return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        case Wall:
            return QImage(WALL_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        case Enter:
            return QImage(ENTER_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        case Border:
            return QImage(BORDER_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        default:
            return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }
}

QImage ObjectMapper::getImage(sGameObject object) {
    if (!object)
        return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    auto &type = object->getTypeInfo();

    if (type == typeid(ExitObject))
        return QImage(EXIT_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    if (type == typeid(CoinObject))
        return QImage(COIN_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    if (type == typeid(SwordObject))
        return QImage(SWORD_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

QImage ObjectMapper::getImage(sEnemyAbstract enemy) {
    if (!enemy)
        return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    auto &type = enemy->getTypeInfo();

    if (type == typeid(Enemy<TheftTemplate>))
        return QImage(GIRL_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    if (type == typeid(Enemy<AttackTemplate>))
        return QImage(STATUE_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    if (type == typeid(Enemy<DebuffTemplate>))
        return QImage(GHOST_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
