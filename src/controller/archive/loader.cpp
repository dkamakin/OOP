#include "controller/archive/loader.h"

void Loader::execute(std::string fileName, sPlayer &player, listEnemies &enemies) {
    input_.open(fileName);

    if (!input_.is_open())
        throw ArchiveException("Wrong file to load from (" + fileName + ')');

    size_t hash;

    enemies.clear();
    FieldMemento fieldBackup;
    EnemyMemento enemyBackup;
    PlayerMemento playerBackup;

    FileStructure structure;
    memset(&structure, 0, sizeof(FileStructure));

    while (input_.read((char*)&hash, sizeof(size_t))) {

        if (hash == typeid(PlayerMemento).hash_code()) {

            if (structure.player_)
                throw ArchiveException("There are several copies of player");

            loadPlayer(playerBackup);
            player->restore(playerBackup);
            structure.player_ = true;
        } else if (hash == typeid(Enemy<TheftTemplate>).hash_code()) {
            loadEnemy(enemyBackup);
            enemies.push_back(sEnemyAbstract(new Enemy<TheftTemplate>(enemyBackup.getEnemy())));
        } else if (hash == typeid(Enemy<AttackTemplate>).hash_code()) {
            loadEnemy(enemyBackup);
            enemies.push_back(sEnemyAbstract(new Enemy<AttackTemplate>(enemyBackup.getEnemy())));
        } else if (hash == typeid(Enemy<DebuffTemplate>).hash_code()) {
            loadEnemy(enemyBackup);
            enemies.push_back(sEnemyAbstract(new Enemy<DebuffTemplate>(enemyBackup.getEnemy())));
        } else if (hash == typeid(FieldMemento).hash_code()) {

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
