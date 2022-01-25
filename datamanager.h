#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QApplication>
#include <QStandardItemModel>
#include "filter.h"
#include "cell.h"


class DataManager : public QObject
{
Q_OBJECT

public:
    DataManager();
    void set(Cell *cell, int row, int column);
    QStandardItemModel * getCells();

protected slots:
    void apply_filter_fixed_color(int row, int column, QColor color);
    void apply_filter_min_max(int row, int column, QColor gradientMin, QColor gradientMax);

private:
    QStandardItemModel *cells;
};

#endif // DATAMANAGER_H
