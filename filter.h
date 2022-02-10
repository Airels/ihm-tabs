#ifndef FILTER_H
#define FILTER_H

#include "cell.h"

/**
 * @brief The Filter abstract class, representing a filter and all of its sub-types
 * @author VIZCAINO Yohan
 */
class Filter
{
public:
    /**
     * @brief apply The apply method, common to all filters, called to apply specific filter on given cell
     * @param cell Cell to apply filter on
     */
    virtual void apply(Cell * cell) = 0;
};

#endif // FILTER_H
