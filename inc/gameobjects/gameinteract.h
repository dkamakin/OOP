#ifndef GAMEINTERACT_H
#define GAMEINTERACT_H

#include "characters/interactstrategy.h"

using sGameInteract = std::shared_ptr <class GameInteract>;

class GameInteract : public InteractStrategy {
public:
    GameInteract() = default;
    void interact(Character &character, sGameObject &object) override;
};

#endif // GAMEINTERACT_H
