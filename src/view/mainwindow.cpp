#include "view/mainwindow.h"
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
                                                    sControllerState(new PlayerTurnState)));
    archive_ = sArchive(new Archive(controller_));

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
            command = sMoveCommand(new MoveCommand(controller_, Up));
            break;
        case Qt::Key_A:
            command = sMoveCommand(new MoveCommand(controller_, Left));
            break;
        case Qt::Key_S:
            command = sMoveCommand(new MoveCommand(controller_, Down));
            break;
        case Qt::Key_D:
            command = sMoveCommand(new MoveCommand(controller_, Right));
            break;
        case Qt::Key_V:
            command = sAttackCommand(new AttackCommand(controller_));
            break;
        case Qt::Key_F10:
            QMessageBox::information(this, "Load", "Loading the game");
            archive_->load("../save.oop");
            break;
        case Qt::Key_F11:
            QMessageBox::information(this, "Save", "Saving the game");
            archive_->save("../save.oop");
            break;
        default:
            return;
    }

    if (command) {
        command->execute();
        mapper_->updateScene(controller_);
    }

    if (controller_->isEnd()) {
        command = sEndGameCommand(new EndGameCommand(controller_));
        command->execute();

        auto reply = askQuestion("The game is over", "Would you like to restart?");
        if (reply == QMessageBox::Yes)
            command = sNewGameCommand(new NewGameCommand(controller_));
        else
            return;

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
