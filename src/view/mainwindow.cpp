#include "view/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow) {

    ui_->setupUi(this);

    screenSize_ = QDesktopWidget().availableGeometry(this).size();
    setFixedSize(screenSize_);
    ui_->view->setFixedSize(screenSize_ * FIELD_COEFFICIENT);

    controller_ = sGameController(new GameController(sField(new Field(GameField::getInstance())),
                                                    sPlayer(new Player(Point2D(), 100, sGameInteract(new GameInteract)))));

    sNewGameCommand command(new NewGameCommand(controller_));
    command->execute();

    initScene();
    updateScene();
    ui_->view->setScene(scene_.get());
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (controller_->isEnd())
        return;

    sCommand command = nullptr;

    switch (event->key()) {
        case Qt::Key_W:
            command = sMoveCommand(new MoveCommand(controller_, UP));
            break;
        case Qt::Key_A:
            command = sMoveCommand(new MoveCommand(controller_, LEFT));
            break;
        case Qt::Key_S:
            command = sMoveCommand(new MoveCommand(controller_, DOWN));
            break;
        case Qt::Key_D:
            command = sMoveCommand(new MoveCommand(controller_, RIGHT));
            break;
        default:
            return;
    }

    if (command) {
        command->execute();
        updateScene();
    }

    if (controller_->isEnd()) {
        auto reply = askQuestion("The game is over", "Would you like to restart?");
        if (reply == QMessageBox::Yes) {
            command = sNewGameCommand(new NewGameCommand(controller_));
        } else {
            command = sEndGameCommand(new EndGameCommand(controller_));
        }

        command->execute();
    }
}

QMessageBox::StandardButton MainWindow::askQuestion(std::string top, std::string bottom) {
    return QMessageBox::question(this, QString::fromStdString(top), QString::fromStdString(bottom), QMessageBox::Yes | QMessageBox::No);
}

void MainWindow::initScene() {
    auto field = controller_->getField();
    auto width = field->getWidth();
    auto height = field->getHeight();
    cellWidth_ = (screenSize_.width() * FIELD_COEFFICIENT) / width;
    cellHeight_ = (screenSize_.height() * FIELD_COEFFICIENT) / height;

    scene_ = sQGraphicsScene(new QGraphicsScene);
    cells_ = sssQGraphicsRectItem(new ssQGraphicsRectItem[height], std::default_delete<ssQGraphicsRectItem[]>());

    for (auto y = 0; y < height; y++) {
        cells_.get()[y] = ssQGraphicsRectItem(new sQGraphicsRectItem[height], std::default_delete<sQGraphicsRectItem[]>());
        for (auto x = 0; x < width; x++) {
            cells_.get()[y].get()[x] = sQGraphicsRectItem(new QGraphicsRectItem(x * cellWidth_, y * cellHeight_,
                                            cellWidth_, cellHeight_, nullptr));
            scene_->addItem(cells_.get()[y].get()[x].get());
        }
    }
}

QImage MainWindow::getImageType(CELL_TYPE type) {
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

QImage MainWindow::getImageObject(sGameObject object) {
    if (!object)
        return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    auto &type = object->getTypeInfo();

    if (type == typeid(ExitObject))
        return QImage(EXIT_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    else if (type == typeid(CoinObject))
        return QImage(COIN_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return QImage(EMPTY_IMAGE).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void MainWindow::updateScene() {
    auto field = controller_->getField();
    auto playerCoords = controller_->getPlayerCoords();
    QImage cellImage;

    for (Cell &cell : *field) {
        auto x = cell.getCoords().getX(), y = cell.getCoords().getY();
        cellImage = getImageType(cell.getType());

        auto rect = cells_.get()[y].get()[x];

        if (cell.getObject()) {
            QPainter painter(&cellImage);
            painter.drawImage(0, 0, getImageObject(cell.getObject()));
        }

        if (!y || !x || y == field->getHeight() - 1 || x == field->getWidth() - 1)
            rect->setBrush(QBrush(QImage(BORDER).scaled(cellWidth_, cellHeight_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

        if (cell.getCoords() == playerCoords) {
            QPainter painter(&cellImage);
            painter.drawImage(0, 0, QImage(PLAYER_IMAGE).scaled(cellWidth_, cellHeight_));
        }

        rect->setBrush(cellImage);
    }
}

void MainWindow::on_actionAuthor_triggered() {
    QMessageBox::information(this, "Author", "Made by Kamakin Daniil, 9381");
}
