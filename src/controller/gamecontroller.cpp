#include "controller/gamecontroller.h"

GameController::GameController(sField object, sControllerState state) :
    field_(object), state_(state) {

    auto &logger = LoggerContext::getInstance();
    logger.subscribe(new FileLogger("logs.txt"));
    logger.subscribe(new ConsoleLogger(std::cout));
}

void GameController::move(Direction direction) {
    state_->moveCharacter(*this, direction);
}

void GameController::playerAttack() {
    state_->playerInteract(*this);
}

void GameController::startTurn() {
    state_->startTurn(*this);
}

void GameController::setTurn(sControllerState state) {
    state_ = state;
}

bool GameController::isOver() {
    if (!player_)
        return true;

    return player_->getEnd();
}

void GameController::newGame() {
    player_ = sPlayer(new Player(Point2D(1, 1), 100, sGameInteract(new GameInteract)));
    enemies_.push_back(sEnemyAbstract(new Enemy<TheftTemplate>(Point2D(1, 4), 100)));
    enemies_.push_back(sEnemyAbstract(new Enemy<AttackTemplate>(Point2D(4, 7), 100)));
    enemies_.push_back(sEnemyAbstract(new Enemy<DebuffTemplate>(Point2D(10, 1), 100)));
    field_->makeMap();
}

void GameController::loadGame(std::string file) {
    Loader loader;

    try {
        loader.execute(file, player_, enemies_);
    } catch (ArchiveException &e) {
        LoggerContext::getInstance() << e.getMessage() << "\n";
    } catch (...) {
        LoggerContext::getInstance() << "Unkown error while loading" << "\n";
    }
}

void GameController::saveGame(std::string file) {
    Saver saver;

    try {
        saver.execute(file, player_, enemies_);
    } catch (ArchiveException &e) {
        LoggerContext::getInstance() << e.getMessage() << "\n";
    } catch (...) {
        LoggerContext::getInstance() << "Unkown error while saving" << "\n";
    }
}

void GameController::endGame() {}

CellType GameController::getType(Point2D &coords) {
    return field_->getType(coords);
}

sPlayer& GameController::getPlayer() {
    return player_;
}

bool GameController::isEnemy(Point2D coords) {
    for (auto &enemy : enemies_)
        if (enemy->getCoords() == coords)
            return true;

    return false;
}

sEnemyAbstract GameController::getEnemy(Point2D coords) {
    for (auto &enemy : enemies_)
        if (enemy->getCoords() == coords)
            return enemy;

    return nullptr;
}

GameController::~GameController() {
    LoggerContext::deleteInstance();
}

std::list<sEnemyAbstract>& GameController::getEnemies() {
    return enemies_;
}

Point2D GameController::getPlayerCoords() {
    return player_->getCoords();
}

std::string GameController::getPlayerInfo() {
    return player_->toString();
}

sField GameController::getField() {
    return field_;
}
