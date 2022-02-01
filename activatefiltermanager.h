#ifndef ACTIVATEFILTERMANAGER_H
#define ACTIVATEFILTERMANAGER_H
#include <QObject>
#include "conditionalcolordialog.h"
#include "datamanager.h"
#include "fixedcolordialog.h"
#include "gradientcolordialog.h"
#include "modulocolordialog.h"
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
    void createLayout();
    QGroupBox* _activeFilter;
    QPushButton* _applyFilterBtn;
    QVBoxLayout* _activeFilterLayout;
    DataManager* dataManager;
    ViewManager* viewManager;
    QString* name = nullptr;
    //filters
    void openFixedColor();
    void openGradientColor();
    void openConditionalColor();
    void openModuloColor();
    //filters item
    FixedColorDialog* fixedColorDialog = nullptr;
    GradientColorDialog* gradientColorDialog = nullptr;
    ConditionalColorDialog* conditionalColorDialog = nullptr;
    ModuloColorDialog* moduloColorDialog = nullptr;
};

#endif // ACTIVATEFILTERMANAGER_H
