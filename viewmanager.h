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
    QModelIndexList *selectionIndexes();

signals:
    void selectionChanged(const QModelIndexList &selectedIndexes);

protected slots:
    void updateSelection(const QItemSelection &selected);

private:
    void setConnexions();

    QModelIndexList *mySelectionIndexes;
    QTableView *myTableView;
};

#endif // VIEWMANAGER_H
