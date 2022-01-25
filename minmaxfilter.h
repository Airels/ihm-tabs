#ifndef MINMAXFILTER_H
#define MINMAXFILTER_H

#include "filter.h"

class MinMaxFilter : public Filter
{
public:
    MinMaxFilter(QColor minColor,QColor maxColor,double minValue,double maxValue);
    void apply(Cell * cell);
private:
    QColor minColor,maxColor;
    double minValue, maxValue;
};


#endif // MINMAXFILTER_H
