#include "controller/archive.h"

Archive::Archive(sGameController controller) : controller_(controller) {}

void Archive::save(std::string fileName) {
    output_.open(fileName);

    if (!output_.is_open())
        return;

    auto player = controller_->getPlayer();

    output_.write("p", 1);
    player->setStrategy(nullptr);
    output_.write((char*)&*player.get(), sizeof(Player));
    output_.close();
}

void Archive::load(std::string fileName) {
    input_.open(fileName);

    if (!input_.is_open())
        return;

    char symbol;

    while (input_.read(&symbol, 1)) {
        if (symbol == 'p') {
            readPlayer(*controller_->getPlayer().get());
        } else {
            std::cerr << "The file is wrong!" << '\n';
            return;
        }
    }

    input_.close();
}

void Archive::readPlayer(Player &player) {
    input_.read((char*)&player, sizeof(Player));
    player.setStrategy(sGameInteract(new GameInteract));
}
