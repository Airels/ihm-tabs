#include "minmaxfilter.h"

MinMaxFilter::MinMaxFilter(QColor minColor,QColor maxColor, double minValue, double maxValue)
{
    this->minColor = minColor;
    this->maxColor = maxColor;
    this->minValue = minValue;
    this->maxValue = maxValue;
}

void MinMaxFilter::apply(Cell *cell){
    int red,blue,green;

    double cellValue = cell->getvalue();
    double percent = cellValue / (maxValue-minValue);

    red = minColor.red() + percent * (maxColor.red()-minColor.red());
    blue = minColor.blue() + percent * (maxColor.blue()-minColor.blue());
    green = minColor.green() + percent * (maxColor.green()-minColor.green());

    QColor color = QColor(red,green,blue);
    cell->setColor(color);

}
