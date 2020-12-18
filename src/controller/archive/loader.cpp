#include "controller/archive/loader.h"

void Loader::execute(std::string fileName, sPlayer &player, listEnemies &enemies) {
    input_.open(fileName);

    if (!input_.is_open())
        throw ArchiveException("Wrong file to load from (" + fileName + ')');

    char symbol;
    enemies.clear();
    FieldMemento fieldBackup;
    FieldStructure structure;
    memset(&structure, 0, sizeof(FieldStructure));

    while (input_.read(&symbol, 1)) {
        if (symbol == HeroType) {
            if (structure.player_)
                throw ArchiveException("There are several copies of player");

            loadPlayer(*player.get());
            structure.player_ = true;
        } else if (symbol == TheftType) {
            enemies.push_back(sEnemyAbstract(new Enemy<TheftTemplate>(loadEnemy().getEnemy())));
        } else if (symbol == AttackType) {
            enemies.push_back(sEnemyAbstract(new Enemy<AttackTemplate>(loadEnemy().getEnemy())));
        } else if (symbol == DebuffType) {
            enemies.push_back(sEnemyAbstract(new Enemy<DebuffTemplate>(loadEnemy().getEnemy())));
        } else if (symbol == FieldType) {
            if (structure.player_)
                throw ArchiveException("There are several copes of field");

            loadField(fieldBackup);
            GameField::getInstance().restore(fieldBackup);
            structure.field_ = true;
        } else {
            throw ArchiveException("Wrong symbol occuried");
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
