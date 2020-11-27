#include "view/mainwindow.h"
#include <QLabel>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow) {

    ui_->setupUi(this);

    screenSize_ = QDesktopWidget().availableGeometry(this).size();
    setFixedSize(screenSize_);
    ui_->view->setFixedSize(screenSize_ * FIELD_COEFFICIENT);

    mapper_ = sLevelMapper(new LevelMapper(screenSize_.width(), screenSize_.height(), FIELD_COEFFICIENT));
    controller_ = sGameController(new GameController(sField(new Field(GameField::getInstance())),
                                                    sPlayer(new Player(Point2D(), 100, sGameInteract(new GameInteract)))));

    sNewGameCommand command(new NewGameCommand(controller_));
    command->execute();

    mapper_->initScene(scene_, controller_);
    mapper_->updateScene(controller_);
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
        mapper_->updateScene(controller_);
    }

    if (controller_->isEnd()) {
        auto reply = askQuestion("The game is over", "Would you like to restart?");
        if (reply == QMessageBox::Yes)
            command = sNewGameCommand(new NewGameCommand(controller_));
        else
            command = sEndGameCommand(new EndGameCommand(controller_));

        command->execute();
    }
}

QMessageBox::StandardButton MainWindow::askQuestion(std::string top, std::string bottom) {
    return QMessageBox::question(this, QString::fromStdString(top), QString::fromStdString(bottom),
                                 QMessageBox::Yes | QMessageBox::No);
}


void MainWindow::on_actionAuthor_triggered() {
    QMessageBox::information(this, "Author", "Made by Kamakin Daniil, 9381");
}
