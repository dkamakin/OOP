#include "view/levelmapper.h"

LevelMapper::LevelMapper(int width, int height, double coefficient) : cellWidth_(width), cellHeight_(height), coefficient_(coefficient) {}

void LevelMapper::initScene(sQGraphicsScene &scene, const sGameController &controller) {
    auto &field = GameField::getInstance();
    auto width = field.getWidth();
    auto height = field.getHeight();
    size_ = Size2D(height, width);

    cellWidth_ = (cellWidth_ / width) * coefficient_;
    cellHeight_ = (cellHeight_ / width) * coefficient_;
    objectMapper_ = sObjectMapper(new ObjectMapper(cellWidth_, cellHeight_));
    playerInfo_ = sQGraphicsTextItem(new QGraphicsTextItem);

    QFont font("Times", 13, QFont::Bold);
    playerInfo_->setFont(font);
    playerInfo_->setPos(0, 0);
    playerInfo_->setPlainText(QString::fromStdString(controller->getPlayerInfo()));
    playerInfo_->setDefaultTextColor(QColor(255, 255, 255));

    scene = sQGraphicsScene(new QGraphicsScene);
    resize(Size2D(height, width), scene);
}

void LevelMapper::resize(Size2D size, sQGraphicsScene &scene) {
    size_ = size;
    cells_ = sssQGraphicsRectItem(new ssQGraphicsRectItem[size.getY()], std::default_delete<ssQGraphicsRectItem[]>());

    for (auto y = 0; y < size.getY(); y++) {
        cells_.get()[y] = ssQGraphicsRectItem(new sQGraphicsRectItem[size.getY()], std::default_delete<sQGraphicsRectItem[]>());

        for (auto x = 0; x < size.getX(); x++) {
            cells_.get()[y].get()[x] = sQGraphicsRectItem(new QGraphicsRectItem(
                                                              x * cellWidth_, y * cellHeight_, cellWidth_, cellHeight_, nullptr)
                                                          );
            scene->addItem(cells_.get()[y].get()[x].get());
        }
    }

    playerInfo_ = sQGraphicsTextItem(new QGraphicsTextItem);

    QFont font("Times", 13, QFont::Bold);
    playerInfo_->setFont(font);
    playerInfo_->setPos(0, 0);
    playerInfo_->setDefaultTextColor(QColor(255, 255, 255));

    scene->addItem(playerInfo_.get());
}

void LevelMapper::updateScene(const sGameController &controller, sQGraphicsScene &scene) {
    auto &field = GameField::getInstance();

    if (size_ != field.getSize())
        resize(field.getSize(), scene);

    auto playerCoords = controller->getPlayerCoords();
    auto enemies = controller->getEnemies();

    for (auto &cell : field) {
        auto x = cell.getCoords().getX(), y = cell.getCoords().getY();
        QImage cellImage = objectMapper_->getImage(cell.getType());
        QPainter painter(&cellImage);

        auto rect = cells_.get()[y].get()[x];

        if (cell.getObject())
            painter.drawImage(0, 0, objectMapper_->getImage(cell.getObject()));

        if (cell.getCoords() == playerCoords)
            painter.drawImage(0, 0, QImage(PLAYER_IMAGE).scaled(cellWidth_, cellHeight_));

        if (controller->isEnemy(cell.getCoords()))
            painter.drawImage(0, 0, objectMapper_->getImage(controller->getEnemy(cell.getCoords())));

        rect->setBrush(cellImage);
    }

    playerInfo_->setPlainText(QString::fromStdString(controller->getPlayerInfo()));
}
