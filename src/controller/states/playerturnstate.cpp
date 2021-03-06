#include "controller/states/playerturnstate.h"

void PlayerTurnState::moveCharacter(GameController& controller, Direction direction) {
    LoggerContext::getInstance() << "[Move]" << "\n";
    auto coords = controller.getPlayerCoords();
    auto player = controller.getPlayer();
    auto &field = GameField::getInstance();

    coords.move(direction);
    player->setDirection(direction);

    auto &object = field.getObject(coords);
    LoggerContext::getInstance() << (object ? "Object: " + object->toString() : "Object: null") << "\n";

    *player += object;

    if (controller.isEnemy(coords)) {
        LoggerContext::getInstance() << player->toString() << "\n\n";
        LoggerContext::getInstance() << "Interacting with the enemy" << "\n\n";

        auto enemy = controller.getEnemy(coords);
        *enemy += *player;
        return;
    }

    if (!field.getPassable(coords)) {
        LoggerContext::getInstance() << player->toString() << "\n\n";
        LoggerContext::getInstance() << "Wrong direction" << "\n\n";
        return;
    }

    LoggerContext::getInstance() << player->toString() << "\n\n";
    player->move(direction);
    endTurn(controller);
}

void PlayerTurnState::playerInteract(GameController &controller) {
    auto coords = controller.getPlayerCoords();
    auto player = controller.getPlayer();
    auto &enemies = controller.getEnemies();
    coords.move(player->getDirection());

    if (controller.isEnemy(coords)) {
        auto enemy = controller.getEnemy(coords);
        *player += enemy;
        *enemy += *player;

        if (enemy->getHealth() <= 0)
            enemies.remove(enemy);
    }

}

void PlayerTurnState::startTurn(GameController&) {}

void PlayerTurnState::endTurn(GameController& controller) {
    controller.setTurn(sEnemyTurnState(new EnemyTurnState));
    controller.startTurn();
}
