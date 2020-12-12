#include "inc/controller/enemyturnstate.h"

void EnemyTurnState::startTurn(GameController& controller) {
    auto enemies = controller.getEnemies();
    auto field = controller.getField();
    srand((unsigned) time(0));

    for (const auto &enemy : enemies) {
        auto coords = enemy->getCoords();
        coords.move(static_cast<Direction>(rand() % 4));

        if (field->getType(coords) == Wall ||
                coords == controller.getPlayerCoords())
            continue;

        enemy->setCoords(coords);
    }

    endTurn(controller);
}

void EnemyTurnState::endTurn(GameController& controller) {
    controller.setTurn(sPlayerTurnState(new PlayerTurnState));
}

void EnemyTurnState::moveCharacter(GameController&, Direction) {}

void EnemyTurnState::playerInteract(GameController&) {}
