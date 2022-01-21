#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QApplication>
#include <QStandardItemModel>
#include "filter.h"
#include "cell.h"

/*
 * Titouan :
 *  - Un seul connect unique MAIS une seule classe unique, avec 1 méthode = 1 filter
 *  La classe contient donc TOUS les paramètres, seulement certains seront renseignés
 *
 *  Yohan :
 *  - 1 classe = 1 filtre, étendant la classe Filtre originelle
 *  MAIS 1 filtre = 1 connect
 */

class DataManager : public QObject
{
Q_OBJECT

public:
    DataManager();
    void set(Cell *cell, int row, int column);
    QStandardItemModel getCells();

protected slots:
    /*
    void apply_filter_min_max(int row, int column, QColor gradientMin, QColor gradientMax); // Yohan
    void apply_filter(Filter::Type filterType); // Titouan
    */

private:
    /*
     * Titouan
    void apply_filter_machin(int row, int column);
    void apply_filter_bidule();
    */
    QStandardItemModel cells;
};

#endif // DATAMANAGER_H
