#include "view/levelmapper.h"

LevelMapper::LevelMapper(int width, int height, double coefficient) : cellWidth_(width), cellHeight_(height), coefficient_(coefficient) {}

void LevelMapper::initScene(sQGraphicsScene &scene, const sGameController &controller) {
    auto field = controller->getField();
    auto width = field->getWidth();
    auto height = field->getHeight();

    cellWidth_ = (cellWidth_ * coefficient_) / width;
    cellHeight_ = (cellHeight_ * coefficient_) / height;
    objectMapper_ = sObjectMapper(new ObjectMapper(cellWidth_, cellHeight_));

    playerInfo_ = new QGraphicsTextItem;
    playerInfo_->setPos(0, 0);
    playerInfo_->setPlainText(QString::fromStdString(controller->getPlayerInfo()));
    playerInfo_->setDefaultTextColor(QColor(255, 255, 255));

    scene = sQGraphicsScene(new QGraphicsScene);
    cells_ = sssQGraphicsRectItem(new ssQGraphicsRectItem[height], std::default_delete<ssQGraphicsRectItem[]>());

    for (auto y = 0; y < height; y++) {
        cells_.get()[y] = ssQGraphicsRectItem(new sQGraphicsRectItem[height], std::default_delete<sQGraphicsRectItem[]>());
        for (auto x = 0; x < width; x++) {
            cells_.get()[y].get()[x] = sQGraphicsRectItem(new QGraphicsRectItem(x * cellWidth_, y * cellHeight_,
                                            cellWidth_, cellHeight_, nullptr));
            scene->addItem(cells_.get()[y].get()[x].get());
        }
    }

    scene->addItem(playerInfo_);
}


void LevelMapper::updateScene(const sGameController &controller) {
    auto field = controller->getField();
    auto playerCoords = controller->getPlayerCoords();
    auto enemies = controller->getEnemies();
    QImage cellImage;

    for (Cell &cell : *field) {
        auto x = cell.getCoords().getX(), y = cell.getCoords().getY();
        cellImage = objectMapper_->getImageType(cell.getType());

        auto rect = cells_.get()[y].get()[x];

        if (cell.getObject()) {
            QPainter painter(&cellImage);
            painter.drawImage(0, 0, objectMapper_->getImageObject(cell.getObject()));
        }

        if (!y || !x || y == field->getHeight() - 1 || x == field->getWidth() - 1)
            rect->setBrush(QBrush(QImage(BORDER_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

        if (cell.getCoords() == playerCoords) {
            QPainter painter(&cellImage);
            painter.drawImage(0, 0, QImage(PLAYER_IMAGE).scaled(cellWidth_, cellHeight_));
        }

        if (controller->isEnemy(cell.getCoords())) {
            QPainter painter(&cellImage);
            painter.drawImage(0, 0, objectMapper_->getImageEnemy(controller->getEnemy(cell.getCoords())));
        }

        rect->setBrush(cellImage);
    }

    playerInfo_->setPlainText(QString::fromStdString(controller->getPlayerInfo()));
}
