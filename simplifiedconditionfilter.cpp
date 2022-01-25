#include "simplifiedconditionfilter.h"

SimplifiedConditionFilter::SimplifiedConditionFilter(double value,QColor underColor, QColor equalColor, QColor aboveColor)
{
    this->underColor = underColor;
    this->equalColor = equalColor;
    this->aboveColor = aboveColor;
    this->value = value;
}

void SimplifiedConditionFilter::apply(Cell *cell){
    double cellValue = cell->getvalue();

    if(cellValue == value){
        cell->setColor(equalColor);
    }else if (cellValue > value) {
        cell->setColor(aboveColor);
    }else{
        cell->setColor(underColor);
    }
}
