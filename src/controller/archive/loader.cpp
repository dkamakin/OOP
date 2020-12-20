#include "controller/archive/loader.h"

void Loader::execute(std::string fileName, sPlayer &player, listEnemies &enemies) {
    input_.open(fileName);

    if (!input_.is_open())
        throw ArchiveException("Wrong file to load from (" + fileName + ')');

    char symbol;
    enemies.clear();
    FieldMemento fieldBackup;
    EnemyMemento enemyBackup;
    PlayerMemento playerBackup;
    FieldStructure structure;
    memset(&structure, 0, sizeof(FieldStructure));

    while (input_.read(&symbol, 1)) {

        if (symbol == HeroType) {
            if (structure.player_)
                throw ArchiveException("There are several copies of player");

            loadPlayer(playerBackup);
            player->restore(playerBackup);
            structure.player_ = true;
        } else if (symbol == TheftType) {
            loadEnemy(enemyBackup);
            enemies.push_back(sEnemyAbstract(new Enemy<TheftTemplate>(enemyBackup.getEnemy())));
        } else if (symbol == AttackType) {
            loadEnemy(enemyBackup);
            enemies.push_back(sEnemyAbstract(new Enemy<AttackTemplate>(enemyBackup.getEnemy())));
        } else if (symbol == DebuffType) {
            loadEnemy(enemyBackup);
            enemies.push_back(sEnemyAbstract(new Enemy<DebuffTemplate>(enemyBackup.getEnemy())));
        } else if (symbol == FieldType) {
            if (structure.field_)
                throw ArchiveException("There are several copies of field");

            loadField(fieldBackup);
            GameField::getInstance().restore(fieldBackup);
            structure.field_ = true;
        } else {
            throw ArchiveException("Wrong symbol occuried");
        }
    }

    if (!structure.field_ || !structure.player_)
        throw ArchiveException("Field or player couldn't be read");

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

void Loader::loadEnemy(EnemyMemento &enemy) {
    input_.read((char*)&enemy, sizeof(EnemyMemento));
}

void Loader::loadPlayer(PlayerMemento &player) {
    input_.read((char*)&player, sizeof(PlayerMemento));
}
