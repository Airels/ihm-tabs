#include "viewmanager.h"
#include <QDebug>

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
    connect(myTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &ViewManager::updateSelection);
}

/*SLOTS*/
void ViewManager::updateSelection(const QItemSelection &selected){
    emit ViewManager::selectionUpdated(selected.indexes());
}

//getters
QTableView *ViewManager::tableView(){
    return myTableView;
}

