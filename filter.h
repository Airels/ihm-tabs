#ifndef FILTER_H
#define FILTER_H

#include "cell.h"

class Filter
{
public:
    enum Type {
        MIN_MAX,
        FIXED,
        SIMPLIFIED_CONDITION,
        MODULO

    };
    const QString typeNames[4] = {"Gradient Color", "Fixed Color", "Conditional value", "Modulo"};

    // Filter();
    virtual void apply(Cell * cell) = 0;
};

#endif // FILTER_H
