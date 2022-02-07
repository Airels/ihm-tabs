#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewmanager.h"
#include "datamanager.h"
#include "filemanager.h"
#include "activatefiltermanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class is in charge of the main graphical window that will be shown to the user.
 *  @author Eddy IKHLEF
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param parent it's parent QWidget.
     * @author Eddy IKHLEF
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /**
     * @brief viewManager reference to the view manager used with the current opened file.
     * @see viewmanager.h
     */
    ViewManager *viewManager;
    /**
     * @brief dataManager reference to the data manager used with the current opened file.
     * @see datamanager.h
     */
    DataManager *dataManager;
    /**
     * @brief fileManager reference to the data manager used with the current opened file.
     * @see filemanager.h
     */
    FileManager *fileManager;
    /**
     * @brief fileManager reference to the acivate filter manager used by the class.
     * @see ActivateFilterManager.h
     */
    ActivateFilterManager *activateFilterManager;
    /**
     * @brief _actionOpenFile reference to the corresponding attribute of the ui.
     */
    QAction* _actionOpenFile;
    /**
     * @brief _actionCloseFile reference to the corresponding attribute of the ui.
     */
    QAction* _actionCloseFile;
    /**
     * @brief _actionSaveAs reference to the corresponding attribute of the ui.
     */
    QAction* _actionSaveAs;
    /**
     * @brief _actionExportAs reference to the corresponding attribute of the ui.
     */
    QAction* _actionExportAs;
    /**
     * @brief _actionGenerate reference to the corresponding attribute of the ui.
     */
    QAction* _actionGenerate;

    /**
     * @brief initAttributes will initialize the class' attributes. It must be called in the class constructor.
     * @author Eddy IKHLEF
     */
    void initAttributes();
    /**
     * @brief initSignals will initialize the class' signals. It must be called in the class constructor.
     * @author Eddy IKHLEF
     */
    void initSignals();
    /**
     * @brief setEnabled allows to enable or disable user interaction with most of the ui.
     * @param value boolean value to enable (true) or disable (false).
     * @author Eddy IKHLEF
     */
    void setEnabled(bool value);
    /**
     * @brief resetInterface allows to reset the interface
     *        (i.e. cleaning the data and active filter, collapsing trees and return to the main tab).
     * @author Eddy IKHLEF
     */
    void resetInterface();


protected slots:
    /**
     * @brief actionOpenFile slot method called when the user interact with the action "Open File" in the main menu.
     * @author Eddy IKHLEF
     */
    void actionOpenFile();
    /**
     * @brief actionCloseFile slot method called when the user interact with the action "Close File" in the main menu.
     * @author Eddy IKHLEF
     */
    void actionCloseFile();
    /**
     * @brief actionSaveAs slot method called when the user interact with the action "Save as Itabs" in the main menu.
     * @author Eddy IKHLEF
     */
    void actionSaveAs();
    /**
     * @brief actionExportAs slot method called when the user interact with the action "Export as Image" in the main menu.
     * @author Eddy IKHLEF
     */
    void actionExportAs();
    /**
     * @brief actionGenerate slot method called when the user interact with the action "Generate" in the main menu.
     * @author Eddy IKHLEF
     */
    void actionGenerate();
    /**
     * @brief activateFilter slot method called when the user interact with the filter selection menu in the ui.
     * It will load the selected filter into the ui.
     * @author Eddy IKHLEF
     */
    void activateFilter();
    /**
     * @brief applyFilter slot method called when the user interact with the filter apply button in the ui.
     * It will applies the selected filter into the currently selected data.
     * @author Eddy IKHLEF
     */
    void applyFilter();
};
#endif // MAINWINDOW_H
