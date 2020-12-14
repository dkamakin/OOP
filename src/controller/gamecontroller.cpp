#include "controller/gamecontroller.h"

GameController::GameController(sField object, sControllerState state) :
    field_(object), state_(state), level_(1) {

    auto &logger = LoggerContext::getInstance();
    logger.subscribe(new FileLogger("logs.txt"));
    logger.subscribe(new ConsoleLogger(std::cout));
}

void GameController::move(Direction direction) {
    state_->moveCharacter(*this, direction);
}

void GameController::nextLevel() {
    if (level_ == 2)
        return;

    level_++;
    loadLevel();
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
    return isEnd() && level_ == 2;
}

void GameController::newGame() {
    Loader loader;
    level_ = 1;
    player_ = sPlayer(new Player(Point2D(1, 1), 100, sGameInteract(new GameInteract)));
    field_->makeMap();
    loadLevel();
}

void GameController::loadGame() {
    Loader loader;

    try {
        loader.execute(QUICK_FILE, player_, enemies_, level_);
    } catch (ArchiveException &e) {
        LoggerContext::getInstance() << e.getMessage() << "\n";
    } catch (...) {
        LoggerContext::getInstance() << "Unkown error while loading" << "\n";
    }
}

void GameController::saveGame() {
    Saver saver;

    try {
        saver.execute(QUICK_FILE, player_, enemies_, level_);
    } catch (ArchiveException &e) {
        LoggerContext::getInstance() << e.getMessage() << "\n";
    } catch (...) {
        LoggerContext::getInstance() << "Unkown error while saving" << "\n";
    }
}

void GameController::loadLevel() {
    Loader loader;
    try {
        loader.execute(LEVEL + std::to_string(level_) + ".oop", player_, enemies_, level_);
    } catch (ArchiveException &e) {
        LoggerContext::getInstance() << e.getMessage() << "\n";
    } catch (...) {
        LoggerContext::getInstance() << "Unkown error while loading" << "\n";
    }
}

void GameController::endGame() {
    player_ = nullptr;
    enemies_.clear();
}

bool GameController::isEnd() {
    if (!player_)
        return true;
    return player_->getEnd();
}

CellType GameController::getType(Point2D &coords) {
    return field_->getType(coords);
}

sPlayer& GameController::getPlayer() {
    return player_;
}

size_t GameController::getPlayerHealth() {
    return player_->getHealth();
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

size_t GameController::getPoints() {
    return player_->getPoints();
}

sField GameController::getField() {
    return field_;
}

void GameController::setEnemies(listEnemies enemies) {
    enemies_ = enemies;
}
