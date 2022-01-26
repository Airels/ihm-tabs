#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QApplication>
#include <QTableView>
#include <QAbstractItemModel>

class ViewManager : public QObject
{
Q_OBJECT
public:
    ViewManager(QTableView *tableView);
    ViewManager(QTableView *tableView, QAbstractItemModel *model);
    ViewManager(QTableView *tableView, QAbstractItemModel *model, QItemSelectionModel *selectionModel);
    QTableView *tableView();

private:
    QTableView *myTableView;
};

#endif // VIEWMANAGER_H
