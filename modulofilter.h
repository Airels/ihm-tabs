#ifndef MODULOFILTER_H
#define MODULOFILTER_H

#include "filter.h"


/**
 * @brief The MinMaxFilter class, an implementation of a filter. Will apply a given color to all cell that have a value equal to 0 modulo [modulo]
 * @author NICOLAI Guillaume
 */
class ModuloFilter : public Filter
{
public:

    /**
     * @brief ModuloFilter Builder to the class, inits the filter with a color and a value.
     * @param modulo the value used to compare all the cells value
     * @param trueColor the color given when cell.value == 0 % modulo
     * @author NICOLAI Guillaume
     */
    ModuloFilter(int modulo, QColor trueColor);
    /**
     * @brief apply Apply the color to cells that equals 0 % modulo.
     * @param cell The cell to apply filter on.
     * @author NICOLAI Guillaume
     */
    void apply(Cell * cell);
private:
    QColor color;
    int moduloValue;
};

#endif // MODULOFILTER_H
