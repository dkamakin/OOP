#ifndef ARCHIVE_H
#define ARCHIVE_H

#include "gamecontroller.h"

#define PLAYER 'P'
#define ATTACK 'A'
#define DEBUFF 'D'
#define THEFT 'T'

using sArchive = std::shared_ptr <class Archive>;

class Archive {
    sGameController controller_;
    std::ofstream output_;
    std::ifstream input_;

public:
    Archive(sGameController controller);
    void save(std::string fileName);
    void load(std::string fileName);

private:
    void savePlayer(Player player);
    void saveEnemy(sEnemyAbstract enemy);

    Character loadCharacter();
    void loadPlayer(Player &player);
};

#endif // ARCHIVE_H
