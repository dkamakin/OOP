#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include "controller/gamecontroller.h"
#include "controller/commands/movecommand.h"
#include "controller/commands/newgamecommand.h"
#include "controller/commands/endgamecommand.h"
#include "controller/commands/attackcommand.h"
#include "controller/commands/savecommand.h"
#include "controller/commands/loadcommand.h"
#include "controller/commands/nextlevelcommand.h"
#include "objectmapper.h"
#include "levelmapper.h"

#define FIELD_COEFFICIENT 0.9

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using sMainWindowUi = std::shared_ptr <Ui::MainWindow>;

class MainWindow : public QMainWindow {
    Q_OBJECT

    QSize screenSize_;

    sMainWindowUi ui_;

    sGameController controller_;
    sQGraphicsScene scene_;
    sLevelMapper mapper_;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private slots:
    void on_actionAuthor_triggered();
    void on_quickSave_triggered();
    void on_quickLoad_triggered();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QMessageBox::StandardButton askQuestion(std::string top, std::string bottom);
};

#endif // MAINWINDOW_H
