#include "controller/archive/saver.h"

void Saver::execute(std::string fileName, sPlayer player, listEnemies &enemies) {
    output_.open(fileName);

    if (!output_.is_open())
        throw ArchiveException("Wrong file to save (" + fileName + ')');

    savePlayer(*player.get());

    for (auto enemy : enemies)
        saveEnemy(enemy);

    output_.close();
}

void Saver::savePlayer(Player player) {
    char symbol = Hero;
    output_.write(&symbol, 1);

    PlayerMemento snapshot = player.save();
    output_.write((char*)&snapshot, sizeof(PlayerMemento));
}

void Saver::saveEnemy(sEnemyAbstract enemy) {
    auto &type = enemy->getTypeInfo();
    char symbol = '\0';

    if (type == typeid (Enemy<AttackTemplate>))
        symbol = Attack;
    if (type == typeid (Enemy<DebuffTemplate>))
        symbol = Debuff;
    if (type == typeid (Enemy<TheftTemplate>))
        symbol = Theft;

    output_.write(&symbol, 1);
    EnemyMemento memento = enemy->save();
    output_.write((char*)&memento, sizeof(EnemyMemento));
}
