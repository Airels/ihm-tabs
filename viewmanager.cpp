#include "viewmanager.h"

TableViewManager::TableViewManager(QAbstractItemModel &model)
{
    myTableView->setModel(&model);
    myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

TableViewManager::TableViewManager(QAbstractItemModel &model, QItemSelectionModel &selectionModel)
{
    myTableView->setModel(&model);
    myTableView->setSelectionModel(&selectionModel);
}

QTableView *TableViewManager::tableView(){
    return myTableView;
}
