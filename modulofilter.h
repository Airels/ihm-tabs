#ifndef MODULOFILTER_H
#define MODULOFILTER_H

#include "filter.h"


class ModuloFilter : public Filter
{
public:
    ModuloFilter(int modulo, QColor trueColor);
    void apply(Cell * cell);
private:
    QColor color;
    int moduloValue;
};

#endif // MODULOFILTER_H
