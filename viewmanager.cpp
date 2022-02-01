#include "viewmanager.h"
#include "cell.h"
#include <QDebug>


ViewManager::ViewManager(QTableView *tableView){
     myTableView = tableView;
     myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
     myTableView->update();
     setConnexions();
}

ViewManager::ViewManager(QTableView *tableView, QStandardItemModel *model)
{
    myTableView = tableView;
    myModel = model;
    myTableView->setModel(myModel);
    myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    myTableView->update();
    updateImage();
    setConnexions();
}

ViewManager::ViewManager(QTableView *tableView, QStandardItemModel *model, QItemSelectionModel *selectionModel)
{
    myTableView = tableView;
    myTableView->setModel(model);
    myTableView->setSelectionModel(selectionModel);
    myTableView->update();
    updateImage();
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

void ViewManager::updateImage(){
    /*
    int rowCount = myModel->rowCount();
    int columnCount = myModel->columnCount();
    for (int r = 0; r < rowCount; r++){
        for (int c = 0; c < columnCount; c++){
           Cell *currentCell = (Cell*) myModel->item(c, r);
           myImage->setPixelColor(c, r, currentCell->getColor());
        }
    }
    */
}

//getters
QTableView *ViewManager::getTableView(){
    return myTableView;
}

QImage *ViewManager::getImage(){
    return myImage;
}
