#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QApplication>
#include <QTableView>
#include <QAbstractItemModel>

class TableViewManager : public QObject
{
Q_OBJECT
public:
    TableViewManager(QAbstractItemModel &model);
    TableViewManager(QAbstractItemModel &model, QItemSelectionModel &selectionModel);
    QTableView *tableView();

private:
    QTableView *myTableView;
};

#endif // VIEWMANAGER_H
