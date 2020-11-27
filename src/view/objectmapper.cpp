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

QImage ObjectMapper::getImageType(CELL_TYPE type) {
    switch (type) {
        case EMPTY:
            return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        case WALL:
            return QImage(WALL_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        case ENTER:
            return QImage(ENTER_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        default:
            return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }
}

QImage ObjectMapper::getImageObject(sGameObject object) {
    if (!object)
        return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    auto &type = object->getTypeInfo();

    if (type == typeid(ExitObject))
        return QImage(EXIT_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    else if (type == typeid(CoinObject))
        return QImage(COIN_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

QImage ObjectMapper::getImageEnemy(sEnemyAbstract enemy) {
    if (!enemy)
        return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    auto &type = enemy->getTypeInfo();

    if (type == typeid(Enemy<TheftTemplate>))
        return QImage(GIRL_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    else if (type == typeid(Enemy<AttackTemplate>))
        return QImage(STATUE_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    else if (type == typeid(Enemy<DebuffTemplate>))
        return QImage(GHOST_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
