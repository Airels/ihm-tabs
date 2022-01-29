#include "viewmanager.h"

ViewManager::ViewManager(QTableView *tableView){
     myTableView = tableView;
     myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
     myTableView->update();
     setConnexions();
}

ViewManager::ViewManager(QTableView *tableView, QAbstractItemModel *model)
{
    myTableView = tableView;
    myTableView->setModel(model);
    myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    myTableView->update();
    setConnexions();
}

ViewManager::ViewManager(QTableView *tableView, QAbstractItemModel *model, QItemSelectionModel *selectionModel)
{
    myTableView = tableView;
    myTableView->setModel(model);
    myTableView->setSelectionModel(selectionModel);
    myTableView->update();
    setConnexions();
}


void ViewManager::setConnexions(){
    connect(myTableView->selectionModel(),SIGNAL(selectionChanged),
            this, SLOT(updateSelection));
}

/*SLOTS*/
void ViewManager::updateSelection(const QItemSelection &selected){
    *mySelectionIndexes = selected.indexes();
    emit ViewManager::selectionChanged(*mySelectionIndexes);
}

//getters
QTableView *ViewManager::tableView(){
    return myTableView;
}

QModelIndexList *ViewManager::selectionIndexes()
{
    return mySelectionIndexes;
}
