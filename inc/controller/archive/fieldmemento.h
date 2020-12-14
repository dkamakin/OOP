#ifndef FIELDMEMENTO_H
#define FIELDMEMENTO_H

#include <vector>
#include "cellmemento.h"
#include "utilities/point2d.h"

using vCellMemento = std::vector <CellMemento>;
using vvCellMemento = std::vector <vCellMemento>;

class FieldMemento {
    Size2D size_;
    vvCellMemento field_;

public:
    FieldMemento() = default;
    FieldMemento(Size2D size, vvCellMemento field);

    Size2D& getSize();
    vvCellMemento& getField();
};

#endif // FIELDMEMENTO_H
