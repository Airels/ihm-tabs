#include "viewmanager.h"
#include "cell.h"
#include <QDebug>


ViewManager::ViewManager(QTableView *tableView){
     myTableView = tableView;
     myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
     myTableView->update();
     myImage = nullptr;
     setConnexions();
}

ViewManager::ViewManager(QTableView *tableView, QStandardItemModel *model)
{
    myTableView = tableView;
    myModel = model;
    myTableView->setModel(myModel);
    myTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    myTableView->update();
    myImage = new QImage(myModel->columnCount(), myModel->rowCount(), QImage::Format_RGB32);
    //updateImage();
    setConnexions();
}

ViewManager::ViewManager(QTableView *tableView, QStandardItemModel *model, QItemSelectionModel *selectionModel)
{
    myTableView = tableView;
    myTableView->setModel(model);
    myTableView->setSelectionModel(selectionModel);
    myTableView->update();
    myImage = new QImage(myModel->columnCount(), myModel->rowCount(), QImage::Format_RGB32);
    //updateImage();
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
