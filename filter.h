#ifndef FILTER_H
#define FILTER_H

#include "cell.h"

class Filter
{
public:
    enum Type {
        MIN_MAX,
        FIXED,
        CONDITION,
        SIMPLIFIED_CONDITION,
        MACHIN,
        BIDULE,
        TRUC
    };
    const QString typeNames[6] = {"Min/Max", "Fixed", "Condition", "Machin", "Bidule", "Truc"};

    // Filter();
    virtual void apply(Cell * cell) = 0;
};

#endif // FILTER_H
