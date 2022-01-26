#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewmanager.h"
#include "datamanager.h"
#include "filemanager.h"

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
    void setEnabled(bool);
    void resetInterface();
    ViewManager *viewManager;
    DataManager *dataManager;
    FileManager *fileManager;


    QAction* _actionOpenFile;
    QAction* _actionCloseFile;
    QAction* _actionSaveAs;
    QAction* _actionExportAs;

protected slots:
    void actionOpenFile();
    void actionCloseFile();
    void actionSaveAs();
    void actionExportAs();
    void activateFilter();
    void applyFilter();
};
#endif // MAINWINDOW_H
