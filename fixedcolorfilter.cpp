#include "fixedcolorfilter.h"

FixedColorFilter::FixedColorFilter(QColor color)
{
    this->color = color;
}

void FixedColorFilter::apply(Cell * cell) {
    cell->setColor(this->color);
}
