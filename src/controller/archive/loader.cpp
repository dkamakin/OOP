#include "controller/archive/loader.h"

void Loader::execute(std::string fileName, sPlayer &player, listEnemies &enemies, int &level) {
    input_.open(fileName);

    if (!input_.is_open())
        throw ArchiveException("Wrong file to load from (" + fileName + ')');

    char symbol;
    enemies.clear();
    FieldMemento fieldBackup;

    while (input_.read(&symbol, 1)) {
        if (symbol == HeroType) {
            loadPlayer(*player.get());
        } if (symbol == TheftType) {
            enemies.push_back(sEnemyAbstract(new Enemy<TheftTemplate>(loadEnemy().getEnemy())));
        } if (symbol == AttackType) {
            enemies.push_back(sEnemyAbstract(new Enemy<AttackTemplate>(loadEnemy().getEnemy())));
        } if (symbol == DebuffType) {
            enemies.push_back(sEnemyAbstract(new Enemy<DebuffTemplate>(loadEnemy().getEnemy())));
        } if (symbol == FieldType) {
            loadField(fieldBackup);
            GameField::getInstance().restore(fieldBackup);
        } if (symbol == LevelType) {
            input_.read((char*)&level, sizeof(int));
        }
    }

    input_.close();
}

void Loader::loadField(FieldMemento &field) {
    auto &size = field.getSize();
    input_.read((char*)&size, sizeof(Size2D));

    if (field.getSize().getY() <= 0 || field.getSize().getX() <= 0)
        throw ArchiveException("Wrong field size");

    auto &array = field.getField();
    array.resize(size.getY());

    for (auto y = 0; y < size.getY(); y++) {
        array[y].resize(size.getX());

        for (auto x = 0; x < size.getX(); x++)
            input_.read((char*)&array[y][x], sizeof(CellMemento));
    }
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
