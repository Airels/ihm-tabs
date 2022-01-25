#include "viewmanager.h"

ViewManager::ViewManager(QAbstractItemModel &model)
{
    myTableView->setModel(&model);
    myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

ViewManager::ViewManager(QAbstractItemModel &model, QItemSelectionModel &selectionModel)
{
    myTableView->setModel(&model);
    myTableView->setSelectionModel(&selectionModel);
}

QTableView *ViewManager::tableView(){
    return myTableView;
}
