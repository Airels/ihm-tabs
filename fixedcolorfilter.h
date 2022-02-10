#ifndef FIXEDCOLORFILTER_H
#define FIXEDCOLORFILTER_H

#include "filter.h"

/**
 * @brief The FixedColorFilter class, an implementation of a filter. Will apply a fixed given color to all cells.
 * @author VIZCAINO Yohan
 */
class FixedColorFilter : public Filter
{
public:
    /**
     * @brief FixedColorFilter Builder to the class, inits the filter with a color to apply on cells
     * @param color The color to apply
     */
    FixedColorFilter(QColor color);

    /**
     * @brief apply Apply the given color to given cell
     * @param cell The cell to apply filter on
     */
    void apply(Cell * cell);
private:
    QColor color;
};

#endif // FIXEDCOLORFILTER_H
