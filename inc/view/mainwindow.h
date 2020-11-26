#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include "controller/gamecontroller.h"
#include "controller/movecommand.h"
#include "controller/newgamecommand.h"
#include "controller/endgamecommand.h"

#define EXIT_IMAGE ":/resources/exit.png"
#define COIN_IMAGE ":/resources/coin.png"
#define WALL_IMAGE ":/resources/wall.png"
#define ENTER_IMAGE ":/resources/enter.png"
#define EMPTY_IMAGE ":/resources/empty.png"
#define PLAYER_IMAGE ":/resources/player.png"
#define BORDER ":/resources/border.png"
#define STATUE ":/resources/enemyStatue.png"
#define GIRL ":/resources/girl.png"
#define GHOST ":/resources/ghost.png"

#define FIELD_COEFFICIENT 0.9

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef std::shared_ptr <Ui::MainWindow> sMainWindowUi;
typedef std::shared_ptr <QGraphicsScene> sQGraphicsScene;
typedef std::shared_ptr <QGraphicsRectItem> sQGraphicsRectItem;
typedef std::shared_ptr <sQGraphicsRectItem> ssQGraphicsRectItem;
typedef std::shared_ptr <ssQGraphicsRectItem> sssQGraphicsRectItem;

class MainWindow : public QMainWindow {
    Q_OBJECT

    int cellWidth_;
    int cellHeight_;

    QSize screenSize_;

    sMainWindowUi ui_;

    sGameController controller_;
    sNewGameCommand newGame_;
    sEndGameCommand endGame_;
    sQGraphicsScene scene_;
    sssQGraphicsRectItem cells_;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private slots:
    void on_actionAuthor_triggered();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QMessageBox::StandardButton askQuestion(std::string top, std::string bottom);
    void updateScene();
    void initScene();
    QImage getImageType(CELL_TYPE type);
    QImage getImageObject(sGameObject object);

};

#endif // MAINWINDOW_H
