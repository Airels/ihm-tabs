#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QApplication>
#include <QTableView>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QImage>

class ViewManager : public QObject
{
Q_OBJECT
public:
    ViewManager(QTableView *tableView);
    ViewManager(QTableView *tableView, QStandardItemModel *model);
    ViewManager(QTableView *tableView, QStandardItemModel *model, QItemSelectionModel *selectionModel);
    //~ViewManager();//TODO
    QTableView *getTableView();
    QImage *getImage();

signals:
    void selectionUpdated(const QModelIndexList &selectedIndexes);

protected slots:
    void updateSelection(const QItemSelection &selected);
    void updateImage();

private:

    void setConnexions();
    QStandardItemModel *myModel;
    QTableView *myTableView;
    QImage *myImage;
};

#endif // VIEWMANAGER_H
