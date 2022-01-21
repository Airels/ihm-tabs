#ifndef FIXEDCOLORFILTER_H
#define FIXEDCOLORFILTER_H

#include "filter.h"

class FixedColorFilter : public Filter
{
public:
    FixedColorFilter(QColor color);
    void apply(Cell * cell);
private:
    QColor color;
};

#endif // FIXEDCOLORFILTER_H
