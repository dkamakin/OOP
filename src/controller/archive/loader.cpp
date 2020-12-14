#include "controller/archive/loader.h"

void Loader::execute(std::string fileName, sPlayer &player, listEnemies &enemies) {
    input_.open(fileName);

    if (!input_.is_open())
        throw ArchiveException("Wrong file to load from (" + fileName + ')');

    char symbol;
    enemies.clear();

    while (input_.read(&symbol, 1)) {
        if (symbol == Hero) {
            loadPlayer(*player.get());
        } if (symbol == Theft) {
            enemies.push_back(sEnemyAbstract(new Enemy<TheftTemplate>(loadEnemy().getEnemy())));
        } if (symbol == Attack) {
            enemies.push_back(sEnemyAbstract(new Enemy<AttackTemplate>(loadEnemy().getEnemy())));
        } if (symbol == Debuff) {
            enemies.push_back(sEnemyAbstract(new Enemy<DebuffTemplate>(loadEnemy().getEnemy())));
        }
    }

    input_.close();
}

EnemyMemento Loader::loadEnemy() {
    EnemyMemento memento;
    input_.read((char*)&memento, sizeof(EnemyMemento));
    return memento;
}

void Loader::loadPlayer(Player &player) {
    PlayerMemento snapshot;
    input_.read((char*)&snapshot, sizeof(PlayerMemento));
    player.restore(snapshot);
}
