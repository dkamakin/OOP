#include "controller/archive/saver.h"

void Saver::execute(std::string fileName, sPlayer player, listEnemies &enemies) {
    output_.open(fileName);

    if (!output_.is_open())
        throw ArchiveException("Wrong file to save (" + fileName + ')');

    savePlayer(*player.get());

    for (auto &enemy : enemies)
        saveEnemy(enemy);

    saveField(GameField::getInstance());

    output_.close();
}

void Saver::saveField(GameField &field) {
    size_t hash = typeid(FieldMemento).hash_code();
    output_.write((char*)&hash, sizeof(size_t));

    FieldMemento snapshot = field.save();
    auto &size = snapshot.getSize();
    auto &array = snapshot.getField();

    output_.write((char*)&size, sizeof(Size2D));

    for (auto y = 0; y < size.getY(); y++)
        for (auto x = 0; x < size.getX(); x++)
            output_.write((char*)&array[y][x], sizeof(CellMemento));

}

void Saver::savePlayer(Player &player) {
    size_t hash = typeid(PlayerMemento).hash_code();
    output_.write((char*)&hash, sizeof(size_t));

    PlayerMemento snapshot = player.save();
    output_.write((char*)&snapshot, sizeof(PlayerMemento));
}

void Saver::saveEnemy(sEnemyAbstract &enemy) {
    size_t hash = enemy->getTypeInfo().hash_code();
    output_.write((char*)&hash, sizeof(size_t));

    EnemyMemento memento = enemy->save();
    output_.write((char*)&memento, sizeof(EnemyMemento));
}
