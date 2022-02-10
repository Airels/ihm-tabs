#ifndef MINMAXFILTER_H
#define MINMAXFILTER_H

#include "filter.h"

/**
 * @brief The MinMaxFilter class, an implementation of a filter. Will apply a gradiant of colors to all selected cells.
 * @author NICOLAI Guillaume
 */
class MinMaxFilter : public Filter
{
public:
    /**
     * @brief MinMaxFilter Builder to the class, inits the filter with two colors and two values.
     * @param maxColor the color given to the maxValue
     * @param minColor the color given to the minValue
     * @param minValue the minimal value of all the selected cells
     * @param maxValue the maximal value of all the selected cells
     * @author NICOLAI Guillaume
     */
    MinMaxFilter(QColor minColor,QColor maxColor,double minValue,double maxValue);
    /**
     * @brief apply give a calculated color to each cell based on minColor and maxColor
     * @param cell The cell to apply filter on
     * @author NICOLAI Guillaume
     */
    void apply(Cell * cell);
private:
    QColor minColor,maxColor;
    double minValue, maxValue;
};


#endif // MINMAXFILTER_H
