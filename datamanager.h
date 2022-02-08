#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QApplication>
#include <QStandardItemModel>
#include "filter.h"
#include "cell.h"


/**
 * @brief The DataManager class, container of loaded table, used to store values, and apply filters on them
 * @author VIZCAINO Yohan
 * @see filter.h To see the abstract class to represent filters
 */
class DataManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(DataManager)

public:
    /**
     * @brief DataManager Builder of the class, to init data representation for future data
     * @author VIZCAINO Yohan
     */
    DataManager();
    ~DataManager();

    /**
     * @brief set Set a new cell in the matrix, to the given coordinates
     * @param cell The cell to set
     * @param row Selected row
     * @param column Selected column
     * @author VIZCAINO Yohan
     */
    void set(Cell *cell, int row, int column);

    /**
     * @brief getCells To get all cells in the matrix
     * @return Pointer to a QStandardItemModel
     * @authors VIZCAINO Yohan
     */
    QStandardItemModel * getCells();

    void generateRandomValue(int row, int column);
    bool generateRandomValue(int row, int column,double minValue, double maxValue,QWidget *parent);

    /**
     * @brief apply_filter_fixed_color When called, apply a fixed given color to the list of cells' indexes
     * @param indexList All cells' index concerned about the filter
     * @param color The color to apply
     * @authors VIZCAINO Yohan
     * @see fixedcolorfilter.h
     */
    void apply_filter_fixed_color(QModelIndexList indexList, QColor color);

    /**
     * @brief apply_filter_min_max When used, apply to the given cells' indexes a gradient of color between given ones, sorted by cells' value
     * @param indexList All cell's index concerned about the filter
     * @param gradientMin The color to apply to the minimal cell value
     * @param gradientMax The color to apply to the maximal cell value
     * @authors VIZCAINO Yohan, NICOLAI Guillaume
     * @see minmaxfilter.h
     */
    void apply_filter_min_max(QModelIndexList indexList, QColor gradientMin, QColor gradientMax);

    /**
     * @brief apply_filter_simplified_condition When used, apply to the given cells' indexes a color according to the given value
     * @param indexList All cell's index concerned about the filter
     * @param value The value to compare
     * @param underColor Color applied if the cell value is below the given value
     * @param equalColor Color applied if the cell value is equal to the given value
     * @param aboveColor Color applied if the cell value is above the given value
     * @authors VIZCAINO Yohan, NICOLAI Guillaume
     * @see simplifiedconditionfilter.h
     */
    void apply_filter_simplified_condition(QModelIndexList indexList, double value, QColor underColor, QColor equalColor, QColor aboveColor);

    /**
     * @brief apply_filter_modulo
     * @param indexList All cell's index concerned about the filter
     * @param moduloValue If the cell is corresponding to the modulo value, then the given color will apply
     * @param color The color to apply
     * @authors VIZCAINO Yohan, NICOLAI Guillaume
     * @see modulofilter.h
     */
    void apply_filter_modulo(QModelIndexList indexList, int moduloValue, QColor color);

private:
    /**
     * @brief apply_filter Will apply given filter to all given cells' indexes
     * @param filter The filter to apply
     * @param indexList All cells' indexes to apply filter to
     */
    void apply_filter(Filter * filter, QModelIndexList indexList);
    QStandardItemModel *cells;
};

#endif // DATAMANAGER_H
