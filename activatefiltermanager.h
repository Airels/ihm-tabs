#ifndef ACTIVATEFILTERMANAGER_H
#define ACTIVATEFILTERMANAGER_H
#include <QObject>
#include "datamanager.h"
#include "viewmanager.h"
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>

class ActivateFilterManager : public QObject
{
public:
    ActivateFilterManager(DataManager* dataManager, ViewManager* viewManager, QGroupBox* _activeFilter, QPushButton* _applyFilterBtn);
    ~ActivateFilterManager();
    void handle(int categoryIndex, int toolIndex);
    void setFilterName(QString name);
    void applyFilter(QModelIndexList* model, int categoryIndex, int toolIndex);

private:
    void clearSelection();
    void updateSelection();
    QGroupBox* _activeFilter;
    QPushButton* _applyFilterBtn;
    QVBoxLayout* _activeFilterLayout;
    DataManager* dataManager;
    ViewManager* viewManager;
    QString* name = nullptr;
    //filters
    void openFixedColor();
};

#endif // ACTIVATEFILTERMANAGER_H
