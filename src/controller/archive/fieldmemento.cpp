#include "controller/archive/fieldmemento.h"

FieldMemento::FieldMemento(Size2D size, vvCellMemento field) : size_(size), field_(field) {}

Size2D& FieldMemento::getSize() {
    return size_;
}

vvCellMemento& FieldMemento::getField() {
    return field_;
}
