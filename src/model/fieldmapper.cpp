#include "model/fieldmapper.h"

FieldMapper::FieldMapper(GameField &field) : field_(field) {}

void FieldMapper::makeMap() {
    auto height = 15, width = 15;
    field_.setSize(Size2D(height, width));
    sExitObjectFactory exitFactory(new ExitObjectFactory);
    sCoinObjectFactory coinFactory(new CoinObjectFactory);
    sSwordObjectFactory swordFactory(new SwordObjectFactory);

    int array[15][15] = {
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3,2,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,1,0,0,0,1,1,1,0,0,0,0,0,0,3},
        {3,1,1,1,1,1,0,1,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,1,1,0,1,1,1,1,1,1,1,3},
        {3,0,0,1,0,1,1,1,0,0,0,0,0,0,3},
        {3,0,0,1,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,1,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,1,1,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,1,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,1,0,0,0,0,0,0,0,0,3},
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
                    };

    for (auto y = 0; y < height; y++)
        for (auto x = 0; x < width; x++) {
            auto type = static_cast<CellType>(array[y][x]);
            field_.setCell(GameCell(type, Point2D(x, y), nullptr, false));

            if (type == Empty || type == Enter)
                field_.getCell(Point2D(x, y)).setPassble(true);

        }

    field_.getCell(Point2D(3, 2)).setObject(coinFactory->createObject());
    field_.getCell(Point2D(10, 7)).setObject(coinFactory->createObject());
    field_.getCell(Point2D(13, 13)).setObject(exitFactory->createObject());
    field_.getCell(Point2D(13, 5)).setObject(swordFactory->createObject());
}
