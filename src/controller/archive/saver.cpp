#include "controller/archive/saver.h"

void Saver::execute(std::string fileName, sPlayer player, listEnemies &enemies, int &level) {
    output_.open(fileName);

    if (!output_.is_open())
        throw ArchiveException("Wrong file to save (" + fileName + ')');

    savePlayer(*player.get());

    for (auto enemy : enemies)
        saveEnemy(enemy);

    saveField(GameField::getInstance());
    saveLevel(level);

    output_.close();
}

void Saver::saveLevel(int level) {
    char symbol = LevelType;
    output_.write((char*)&symbol, sizeof(char));
    output_.write((char*)&level, sizeof(int));
}

void Saver::saveField(GameField &field) {
    char symbol = FieldType;
    output_.write(&symbol, sizeof(char));

    FieldMemento snapshot = field.save();
    auto &size = snapshot.getSize();
    auto &array = snapshot.getField();

    output_.write((char*)&size, sizeof(Size2D));

    for (auto y = 0; y < size.getY(); y++)
        for (auto x = 0; x < size.getX(); x++)
            output_.write((char*)&array[y][x], sizeof(CellMemento));

}

void Saver::savePlayer(Player player) {
    char symbol = HeroType;
    output_.write(&symbol, sizeof(char));

    PlayerMemento snapshot = player.save();
    output_.write((char*)&snapshot, sizeof(PlayerMemento));
}

void Saver::saveEnemy(sEnemyAbstract enemy) {
    auto &type = enemy->getTypeInfo();
    char symbol = '\0';

    if (type == typeid (Enemy<AttackTemplate>))
        symbol = AttackType;
    if (type == typeid (Enemy<DebuffTemplate>))
        symbol = DebuffType;
    if (type == typeid (Enemy<TheftTemplate>))
        symbol = TheftType;

    output_.write(&symbol, sizeof(char));
    EnemyMemento memento = enemy->save();
    output_.write((char*)&memento, sizeof(EnemyMemento));
}
