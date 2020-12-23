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
    controller_ = sGameController(new GameController(GameField::getInstance(), sControllerState(new PlayerTurnState)));
    faq_ = sFAQWindow(new FAQwindow);

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
        case Qt::Key_O:
            command = sSaveCommand(new SaveCommand(controller_, QUICK_FILE));
            break;
        case Qt::Key_P:
            command = sLoadCommand(new LoadCommand(controller_, QUICK_FILE));
            break;
        default:
            return;
    }

    if (command) {
        try {
            command->execute();
        }  catch (ArchiveException &e) {
            QMessageBox::warning(this, "Error during save/load", QString::fromStdString(e.getMessage()));
            return;
        }
    }

    mapper_->updateScene(controller_, scene_);

    if (controller_->isOver()) {
        QMessageBox::information(nullptr, "The end", "The game is over");
        command = sEndGameCommand(new EndGameCommand(controller_));
        command->execute();
    }
}

void MainWindow::on_actionLoad_triggered() {
    auto file = QFileDialog::getOpenFileName(this, "Select a file to load the game from").toStdString();
    sCommand command = sLoadCommand(new LoadCommand(controller_, file));
    command->execute();
    mapper_->updateScene(controller_, scene_);
}

void MainWindow::on_actionSave_triggered() {
    auto file = QFileDialog::getSaveFileName(this, "Select a file to save the game to").toStdString();
    sCommand command = sSaveCommand(new SaveCommand(controller_, file));
    command->execute();
}

void MainWindow::on_actionFAQ_triggered() {
    faq_->exec();
}

void MainWindow::on_actionAuthor_triggered() {
    QMessageBox::information(this, "Author", "Kamakin Daniil, ETU (hell)");
}
