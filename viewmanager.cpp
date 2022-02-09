#include "viewmanager.h"
#include "cell.h"
#include <QDebug>
#include <QHeaderView>


ViewManager::ViewManager(QTableView *tableView){
     myTableView = tableView;
     myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
     myTableView->horizontalHeader()->setSortIndicatorShown(true);
     myTableView->update();
     myImage = nullptr;
     setConnexions();
}

ViewManager::ViewManager(QTableView *tableView, QStandardItemModel *model) :
    ViewManager(tableView)
{
    myModel = model;
    myTableView->setModel(myModel);
    myImage = new QImage(myModel->columnCount(), myModel->rowCount(), QImage::Format_RGB32);
    for (int i = 0; i < model->rowCount(); i++) {
        for (int j = 0; j < model->columnCount(); j++) {
            model->item(i, j)->setData(int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);
        }
    }
    updateImage();
}

ViewManager::ViewManager(QTableView *tableView, QStandardItemModel *model, QItemSelectionModel *selectionModel) :
    ViewManager(tableView, model)
{
    myTableView->setSelectionModel(selectionModel);
}

ViewManager::~ViewManager(){
    //delete myModel;
    //delete myTableView;
    delete myImage;
}


void ViewManager::setConnexions(){
    connect(myTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &ViewManager::updateSelection);
    connect(myTableView->horizontalHeader(), SIGNAL(sortIndicatorChanged(int, Qt::SortOrder)),
            this, SIGNAL(sortRequested(int, Qt::SortOrder)));
}



/*SLOTS*/
void ViewManager::updateSelection(const QItemSelection &selected){
    emit ViewManager::selectionUpdated(selected.indexes());
}

void ViewManager::updateImage(){
    if (myImage == nullptr){
        qDebug() << "myImage not initialized" << Qt::endl;//plus propre avec une erreur, mais pas nécessaire
        return;
    }
    //qDebug() <<"image size :" << myImage->size() << Qt::endl;
    int columnCount = myModel->columnCount();
    int rowCount = myModel->rowCount();
    for (int x = 0;  x < columnCount; x++){
        for (int y = 0; y < rowCount; y++){
           Cell *currentCell = (Cell*) myModel->item(y, x);
           //qDebug() << "set Pixel Color : x =" << x <<", y ="<<y<<"color =" <<currentCell->getColor()<<Qt::endl;
           myImage->setPixelColor(x, y, currentCell->getColor());
        }
    }

}

//getters
QTableView *ViewManager::getTableView(){
    return myTableView;
}

QImage *ViewManager::getImage(){
    return myImage;
}
