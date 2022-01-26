#include "viewmanager.h"

ViewManager::ViewManager(QTableView *tableView){
     myTableView = tableView;
     myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
     myTableView->update();
}

ViewManager::ViewManager(QTableView *tableView, QAbstractItemModel *model)
{
    myTableView = tableView;
    myTableView->setModel(model);
    myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    myTableView->update();
}

ViewManager::ViewManager(QTableView *tableView, QAbstractItemModel *model, QItemSelectionModel *selectionModel)
{
    myTableView = tableView;
    myTableView->setModel(model);
    myTableView->setSelectionModel(selectionModel);
    myTableView->update();
}

QTableView *ViewManager::tableView(){
    return myTableView;
}
