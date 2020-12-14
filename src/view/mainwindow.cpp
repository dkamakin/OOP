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

    sNewGameCommand command(new NewGameCommand(controller_));
    command->execute();

    mapper_->initScene(scene_, controller_);
    mapper_->updateScene(controller_, scene_);
    ui_->view->setScene(scene_.get());
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (controller_->isOver())
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
        default:
            return;
    }

    if (command)
        command->execute();

    if (controller_->isEnd() && !controller_->isOver()) {
        QMessageBox::information(this, "Going deeper", "Going to the next level");
        command = sNextLevelCommand(new NextLevelCommand(controller_));
        command->execute();
        mapper_->resize(GameField::getInstance().getSize(), scene_);
    }

    if (controller_->isOver()) {
        QMessageBox::information(nullptr, "The end", "The game is over, you won a beer!");
        command = sEndGameCommand(new EndGameCommand(controller_));
        command->execute();
        return;
    }

    mapper_->updateScene(controller_, scene_);
}

void MainWindow::on_quickLoad_triggered() {
    sCommand command = sLoadCommand(new LoadCommand(controller_));
    command->execute();
    mapper_->updateScene(controller_, scene_);
}

void MainWindow::on_quickSave_triggered() {
    sCommand command = sSaveCommand(new SaveCommand(controller_));
    command->execute();
    mapper_->updateScene(controller_, scene_);
}

void MainWindow::on_actionAuthor_triggered() {
    QMessageBox::information(this, "Author", "Made by Kamakin Daniil, 9381");
}
