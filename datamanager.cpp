#include "datamanager.h"
#include "fixedcolorfilter.h"
#include "minmaxfilter.h"
#include "simplifiedconditionfilter.h"
#include "modulofilter.h"
#include <float.h>
#include <QRandomGenerator>
#include <QDebug>
#include <QMessageBox>

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

void DataManager::apply_filter_modulo(QModelIndexList indexList, int moduloValue, QColor color){
    Filter *filter = new ModuloFilter(moduloValue,color);
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

void DataManager::generateRandomValue(int row, int column){
    cells->clear();
    cells->setColumnCount(column);

    for(int rowIndex = 0; rowIndex < row; rowIndex++){
        QList<QStandardItem *> items;
        for(int columnIndex = 0; columnIndex < column; columnIndex++){

            //Cell *cell = (Cell *)(cells->item(rowIndex,columnIndex));

            QRandomGenerator generator;
            double value = generator.generateDouble() * DBL_MAX;
            double sign = generator.generateDouble();
            if(sign < 0.5){
                //cell->setValue(-value);
                items.append(new Cell(-value));
            }else{
                //cell->setValue(value);
                items.append(new Cell(value));
            }

        }
        cells->appendRow(items);
    }
}

bool DataManager::generateRandomValue(int row, int column,double minValue, double maxValue, QWidget *parent){
    double value;
    if(minValue > maxValue){
        QMessageBox::warning(parent,"Error in values", "minimal value must be inferior or equal to the maximal value",QMessageBox::Ok);
        return false;
    }else if(maxValue < minValue){
        QMessageBox::warning(parent,"Error in values", "maximal value must be superior or equal to the minimal value",QMessageBox::Ok);
        return false;
    }
    cells->clear();
    cells->setColumnCount(column);

    /*for(int i=0;i<column;i++){
        items.append(new Cell(0));
    }

    cells->setColumnCount(column);

    for(int i=0;i<row;i++){
        cells->appendRow(items);
    }
    */

    for(int rowIndex = 0; rowIndex < row; rowIndex++){
        QList<QStandardItem *> items;
        for(int columnIndex = 0; columnIndex < column; columnIndex++){

            //Cell *cell = (Cell *)(cells->item(rowIndex,columnIndex));
            QRandomGenerator generator;
            if(minValue >= 0 && maxValue >=0){
                value = minValue + generator.generateDouble() * (maxValue - minValue);
                //cell->setValue(value);
                items.append(new Cell(-value));
            }else if(minValue < 0 && maxValue >= 0){
                double tempMinValue = minValue/4;
                double tempMaxValue = maxValue/4;
                double signValue = tempMaxValue /(tempMaxValue-tempMinValue); //probabilité d'etre positif on divise les Max/MinValue par 4 pour gérer le DBL_MAX/ DBL_MIN
                double sign = generator.generateDouble();
                if(sign >= signValue){
                    value = generator.generateDouble()*minValue;
                    //cell->setValue(-value);
                    items.append(new Cell(-value));
                }else{
                    value = generator.generateDouble()*maxValue;
                    //cell->setValue(value);
                    items.append(new Cell(value));
                }

            }else if(minValue < 0 && maxValue < 0){
                value = maxValue + generator.generateDouble() * (minValue - maxValue);
                //cell->setValue(value);
                items.append(new Cell(value));
            }
        }
        cells->appendRow(items);
    }
    return true;

}
