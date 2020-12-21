#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include "gamefield.h"
#include "gameobjects/coin/coinobjectfactory.h"
#include "gameobjects/exit/exitobjectfactory.h"
#include "gameobjects/sword/swordobjectfactory.h"

using sField = std::shared_ptr <class FieldMapper>;

class FieldMapper {
    GameField &field_;

public:
    explicit FieldMapper(GameField &f);
    void makeMap();
};

#endif // FIELD_H
