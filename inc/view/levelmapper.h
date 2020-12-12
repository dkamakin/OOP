#ifndef LEVELMAPPER_H
#define LEVELMAPPER_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPainter>
#include "controller/gamecontroller.h"
#include "objectmapper.h"

using sQGraphicsScene = std::shared_ptr <QGraphicsScene>;
using sQGraphicsRectItem = std::shared_ptr <QGraphicsRectItem>;
using ssQGraphicsRectItem = std::shared_ptr <sQGraphicsRectItem>;
using sssQGraphicsRectItem = std::shared_ptr <ssQGraphicsRectItem>;
using sQGraphicsTextItem = std::shared_ptr <QGraphicsTextItem>;
using sQGraphicsTextItem = std::shared_ptr <QGraphicsTextItem>;
using sLevelMapper = std::shared_ptr <class LevelMapper>;

class LevelMapper {
    sObjectMapper objectMapper_;
    sQGraphicsTextItem playerInfo_;
    sssQGraphicsRectItem cells_;
    int cellWidth_;
    int cellHeight_;
    double coefficient_;

public:
    LevelMapper(int width, int height, double coefficient);
    void initScene(sQGraphicsScene &scene, const sGameController &controller);
    void updateScene(const sGameController &controller);
};

#endif // LEVELMAPPER_H
