#ifndef SIMPLIFIEDCONDITIONFILTER_H
#define SIMPLIFIEDCONDITIONFILTER_H

#include "filter.h"

/**
 * @brief The SimplifiedConditionFilter class, will give a color to all selected cell based on their value and a given value
 * @author NICOLAI Guillaume
 */
class SimplifiedConditionFilter : public Filter
{
public:
    /**
     * @brief SimplifiedConditionFilter Builder to the class, inits the filter with three colors and one value.
     * @param value the value that will be used to compare every cell values
     * @param underColor the color given to cell that have a value inferior than value
     * @param equalColor the color given to cell that have a value equal to value
     * @param aboveColor the color given to cell that have a value superior than value
     * @author NICOLAI Guillaume
     */
    SimplifiedConditionFilter(double value,QColor underColor, QColor equalColor,QColor aboveColor);
    /**
     * @brief apply Apply one of the three given Color to the cell based on the cell value.
     * @param cell The cell to apply filter on.
     * @author NICOLAI Guillaume
     */
    void apply(Cell * cell);
private:
    QColor underColor,aboveColor,equalColor;
    double value;
};

#endif // SIMPLIFIEDCONDITIONFILTER_H
