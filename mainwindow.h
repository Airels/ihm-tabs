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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ViewManager *viewManager;
    DataManager *dataManager;
    FileManager *fileManager;
    ActivateFilterManager *activateFilterManager;
    QAction* _actionOpenFile;
    QAction* _actionCloseFile;
    QAction* _actionSaveAs;
    QAction* _actionExportAs;
    QAction* _actionGenerate;
    QVBoxLayout* _activeFilterLayout;

    void initAttributes();
    void initSignals();
    void setEnabled(bool);
    void resetInterface();


protected slots:
    void actionOpenFile();
    void actionCloseFile();
    void actionSaveAs();
    void actionExportAs();
    void actionGenerate();

    void activateFilter();
    void applyFilter();
};
#endif // MAINWINDOW_H
