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
    qDebug() << "selectionModel : " << myTableView->selectionModel();
    connect(myTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &ViewManager::updateSelection);
}

/*SLOTS*/
void ViewManager::updateSelection(const QItemSelection &selected){
    *mySelectionIndexes = selected.indexes();
    emit ViewManager::selectionUpdated(*mySelectionIndexes);
}

//getters
QTableView *ViewManager::tableView(){
    return myTableView;
}

QModelIndexList *ViewManager::selectionIndexes()
{
    return mySelectionIndexes;
}


