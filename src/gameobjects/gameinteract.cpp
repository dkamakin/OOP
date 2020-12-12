#include "gameobjects/gameinteract.h"

void GameInteract::interact(Character &character, sGameObject &object) {
    if (!object)
        return;

    object->action(character);

    if (object->isDisposable())
        object = nullptr;
}
