#ifndef SIMPLIFIEDCONDITIONFILTER_H
#define SIMPLIFIEDCONDITIONFILTER_H

#include "filter.h"

class SimplifiedConditionFilter : public Filter
{
public:
    SimplifiedConditionFilter(double value,QColor underColor, QColor equalColor,QColor aboveColor);
    void apply(Cell * cell);
private:
    QColor underColor,aboveColor,equalColor;
    double value;
};

#endif // SIMPLIFIEDCONDITIONFILTER_H
