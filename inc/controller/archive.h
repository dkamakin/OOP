#ifndef ARCHIVE_H
#define ARCHIVE_H

#include "gamecontroller.h"

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
    void readPlayer(Player &player);
};

#endif // ARCHIVE_H
