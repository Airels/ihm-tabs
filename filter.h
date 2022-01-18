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
        MACHIN,
        BIDULE,
        TRUC
    };
    const QString typeNames[6] = {"Min/Max", "Fixed", "Condition", "Machin", "Bidule", "Truc"};

    Filter();
    virtual void apply(Cell cell);
};

#endif // FILTER_H
