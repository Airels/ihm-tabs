#ifndef ACTIVATEFILTERMANAGER_H
#define ACTIVATEFILTERMANAGER_H
#include <QObject>
#include "conditionalcolordialog.h"
#include "datamanager.h"
#include "fixedcolordialog.h"
#include "gradientcolordialog.h"
#include "modulocolordialog.h"
#include "sortdialog.h"
#include "viewmanager.h"
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>

/**
 * @brief The ActivateFilterManager class is in charge of instantiating the QDialog of the implemented filters and to use them,
 *        either to show them in the ui or to fetch datas from them when the current filter is applied.
 * @author IKHLEF Eddy
 */
class ActivateFilterManager : public QObject
{
public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param dataManager to apply the filters on the current data.
     * @param _activeFilter to append and remove the selected filter to the current groupBox in the ui.
     * @param _applyFilterBtn for a safety measure to be able to disable or enable the apply filter button.
     * @author IKHLEF Eddy
     */
    ActivateFilterManager(DataManager* dataManager, QGroupBox* _activeFilter, QPushButton* _applyFilterBtn);
    ~ActivateFilterManager();
    /**
     * @brief handle the current filter to call.
     * @param categoryIndex of the selected filter.
     * @param toolIndex of the selected filter.
     * @author IKHLEF Eddy
     */
    void handle(int categoryIndex, int toolIndex);
    /**
     * @brief setFilterName allows to change the labelled name of the given groupBox.
     * @param name
     * @author IKHLEF Eddy
     */
    void setFilterName(QString name);
    /**
     * @brief applyFilter allows to apply the called filter on the model.
     * @param model
     * @param categoryIndex of the selected filter.
     * @param toolIndex of the selected filter.
     * @author IKHLEF Eddy
     */
    void applyFilter(QModelIndexList* model, int categoryIndex, int toolIndex);

private:
    /**
     * @brief _activeFilter reference to the corresponding attribute of the ui.
     */
    QGroupBox* _activeFilter;
    /**
     * @brief _applyFilterBtn reference to the corresponding attribute of the ui.
     */
    QPushButton* _applyFilterBtn;
    /**
     * @brief _activeFilterLayout reference to the layout for _activeFilter element.
     */
    QVBoxLayout* _activeFilterLayout = nullptr;
    /**
     * @brief dataManager reference to the data manager used with the current opened file.
     * @see datamanager.h
     */
    DataManager* dataManager;
    /**
     * @brief name to set and use for the _activeFilter element.
     */
    QString* name = nullptr;
    /**
     * @brief fixedColorDialog reference to a QDialog element for the "fixed color" filter.
     */
    FixedColorDialog* fixedColorDialog = nullptr;
    /**
     * @brief fixedColorDialog reference to a QDialog element for the "gradient color" filter.
     */
    GradientColorDialog* gradientColorDialog = nullptr;
    /**
     * @brief fixedColorDialog reference to a QDialog element for the "conditional color" filter.
     */
    ConditionalColorDialog* conditionalColorDialog = nullptr;
    /**
     * @brief fixedColorDialog reference to a QDialog element for the "modulo color" filter.
     */
    ModuloColorDialog* moduloColorDialog = nullptr;
    /**
     * @brief sortDialog reference to a QDialog element for the "sort" filter.
     */
    SortDialog* sortDialog = nullptr;

    /**
     * @brief clearSelection will clear the active filter fields in the ui
     *                      (i.e. the filer's box name and the elements of the previously active will be removed).
     * @author IKHLEF Eddy
     */
    void clearSelection();
    /**
     * @brief updateSelection will update the active filter fields in the ui
     *        (i.e. the box name will be updated).
     * @author IKHLEF Eddy
     */
    void updateSelection();
    /**
     * @brief createLayout will instanciates the current layout of the filter's box.
     * @author IKHLEF Eddy
     */
    void createLayout();
    /**
     * @brief openFixedColor will showcase the corresponding filter in the ui using _activeFilter element.
     * @author IKHLEF Eddy
     */
    void openFixedColor();
    /**
     * @brief openGradientColor will showcase the corresponding filter in the ui using _activeFilter element.
     * @author IKHLEF Eddy
     */
    void openGradientColor();
    /**
     * @brief openConditionalColor will showcase the corresponding filter in the ui using _activeFilter element.
     * @author IKHLEF Eddy
     */
    void openConditionalColor();
    /**
     * @brief openModuloColor will showcase the corresponding filter in the ui using _activeFilter element.
     * @author IKHLEF Eddy
     */
    void openModuloColor();
    /**
     * @brief openSort will showcase the corresponding filter in the ui using _activeFilter element.
     * @author IKHLEF Eddy
     */
    void openSort();
};

#endif // ACTIVATEFILTERMANAGER_H
