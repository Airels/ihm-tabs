#include "datamanager.h"
#include "fixedcolorfilter.h"
#include "minmaxfilter.h"
#include "simplifiedconditionfilter.h"
#include <float.h>

DataManager::DataManager()
{
    cells = new QStandardItemModel();
}

DataManager::~DataManager() {
    delete cells;
}

void DataManager::apply_filter_fixed_color(QModelIndexList indexList, QColor color) {
    Filter *filter = new FixedColorFilter(color);
    apply_filter(filter, indexList);
    delete filter;
}

void DataManager::apply_filter_min_max(QModelIndexList indexList, QColor minColor, QColor maxColor){
    double minValue = DBL_MAX;
    double maxValue = DBL_MIN;
    double currentValue;

    for (const QModelIndex &index : indexList){

        Cell *cell = (Cell *)(cells->item(index.row(),index.column()));
        currentValue = cell->getvalue();

        if(currentValue > maxValue){
            maxValue = currentValue;
        }

        if(currentValue < minValue){
            minValue = currentValue;
        }

    }
    Filter *filter = new MinMaxFilter(minColor,maxColor,minValue,maxValue);
    apply_filter(filter,indexList);
    delete filter;
}

void DataManager::apply_filter_simplified_condition(QModelIndexList indexList, double value, QColor underColor, QColor equalColor, QColor aboveColor){
    Filter *filter = new SimplifiedConditionFilter(value,underColor,equalColor,aboveColor);
    apply_filter(filter,indexList);
    delete filter;
}

void DataManager::apply_filter(Filter *filter, QModelIndexList indexList){

    for (const QModelIndex &index : indexList){
        filter->apply((Cell *) cells->item(index.row(), index.column()));
    }
}

QStandardItemModel * DataManager::getCells() {
    return this->cells;
}

// row = 1; column = -1;
/*
void DataManager::apply_filter_min_max(int row, int column, QColor gradientMin, QColor gradientMax) {
    Filter filter = Filter(fjjqzd);

    for (int column = 0; column < max; column++) {
        Cell cell = cells.item(row, column);
        filter.apply(cell);
    }
}
*/
