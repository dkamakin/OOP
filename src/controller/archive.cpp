#include "controller/archive.h"

Archive::Archive(sGameController controller) : controller_(controller) {}

void Archive::save(std::string fileName) {
    output_.open(fileName);

    if (!output_.is_open())
        return;

    auto player = controller_->getPlayer();
    listEnemies enemies = controller_->getEnemies();

    savePlayer(*player.get());

    for (auto enemy : enemies)
        saveEnemy(enemy);

    output_.close();
}


void Archive::load(std::string fileName) {
    input_.open(fileName);

    if (!input_.is_open())
        return;

    char symbol;
    listEnemies enemies;

    while (input_.read(&symbol, 1)) {
        if (symbol == PLAYER) {
            loadPlayer(*controller_->getPlayer().get());
        } if (symbol == THEFT) {
            enemies.push_back(sEnemyAbstract(new Enemy<TheftTemplate>(loadCharacter())));
        } if (symbol == ATTACK) {
            enemies.push_back(sEnemyAbstract(new Enemy<AttackTemplate>(loadCharacter())));
        } if (symbol == DEBUFF) {
            enemies.push_back(sEnemyAbstract(new Enemy<DebuffTemplate>(loadCharacter())));
        }
    }

    controller_->setEnemies(enemies);
    input_.close();
}

Character Archive::loadCharacter() {
    Character character;
    input_.read((char*)&character, sizeof(Character));
    return character;
}

void Archive::savePlayer(Player player) {
    output_.write("P", 1);
    player.setStrategy(nullptr);
    output_.write((char*)&player, sizeof(Player));
}

void Archive::saveEnemy(sEnemyAbstract enemy) {
    auto &type = enemy->getTypeInfo();
    if (type == typeid (Enemy<AttackTemplate>)) {
        char symbol = ATTACK;
        output_.write(&symbol, 1);
    } if (type == typeid (Enemy<DebuffTemplate>)) {
        char symbol = DEBUFF;
        output_.write(&symbol, 1);
    } if (type == typeid (Enemy<TheftTemplate>)) {
        char symbol = THEFT;
        output_.write(&symbol, 1);
    }

    Character character = *enemy.get();
    output_.write((char*)&character, sizeof(Character));
}

void Archive::loadPlayer(Player &player) {
    input_.read((char*)&player, sizeof(Player));
    player.setStrategy(sGameInteract(new GameInteract));
}
