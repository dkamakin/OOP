#include "controller/gamecontroller.h"
#include <QMessageBox>

GameController::GameController(sField object, sPlayer player) : field_(object), player_(player), moveCount_(0) {
    auto &logger = LoggerContext::getInstance();
    logger.subscribe(new FileLogger("logs.txt"));
    logger.subscribe(new ConsoleLogger(std::cout));
    enemy = new Enemy<TheftTemplate>;
}

GameController::~GameController() {
    LoggerContext::deleteInstance();
}

Point2D GameController::getPlayerCoords() {
    return player_->getCoords();
}

size_t GameController::getPoints() {
    return player_->getPoints();
}

sField GameController::getField() {
    return field_;
}

void GameController::newGame() {
    field_->makeMap();
    player_ = sPlayer(new Player(Point2D(1, 1), 100, sGameInteract(new GameInteract)));
}

void GameController::endGame() {
    player_ = nullptr;
    field_->deleteField();
}

bool GameController::isEnd() {
    if (!player_)
        return true;
    return player_->getEnd();
}

CELL_TYPE GameController::getType(Point2D &coords) {
    return field_->getType(coords);
}

size_t GameController::getPlayerHealth() {
    return player_->getHealth();
}

void GameController::movePlayer(DIRECTION direction) {
    LoggerContext::getInstance() << "[Move #" << std::to_string(++moveCount_) << "]\n";
    auto oldCoords = getPlayerCoords();

    player_->move(direction);

    auto &object = field_->getObject(getPlayerCoords());
    LoggerContext::getInstance() << (object ? "Object: " + object->toString() : "Object: null") << "\n";
    if (getPlayerCoords() == Point2D(5, 1)) {
        std::cout << "123" << '\n';
        QMessageBox::information(nullptr, "Interacting", "Go");
        Player &player = *player_.get();
        enemy->interact(player);
    }


    *player_ += object;

    if (field_->getType(getPlayerCoords()) == WALL) {
        LoggerContext::getInstance() << player_->toString() << "\n\n";
        LoggerContext::getInstance() << "Wrong direction" << "\n\n";
        player_->setCoords(oldCoords);
        return;
    }

    LoggerContext::getInstance() << player_->toString() << "\n\n";
}
