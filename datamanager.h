#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QApplication>
#include <QStandardItemModel>
#include "filter.h"
#include "cell.h"


class DataManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(DataManager)

public:
    DataManager();
    ~DataManager();
    void set(Cell *cell, int row, int column);
    QStandardItemModel * getCells();
    void generateRandomValue(int row, int column);
    void apply_filter_fixed_color(QModelIndexList indexList, QColor color);

public slots:
    void apply_filter_min_max(QModelIndexList indexList, QColor gradientMin, QColor gradientMax);
    void apply_filter_simplified_condition(QModelIndexList indexList, double value, QColor underColor, QColor equalColor, QColor aboveColor);
    void apply_filter_modulo(QModelIndexList indexList, int moduloValue, QColor color);

private:
    void apply_filter(Filter * filter, QModelIndexList indexList);
    QStandardItemModel *cells;
};

#endif // DATAMANAGER_H
