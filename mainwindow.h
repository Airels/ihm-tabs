#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

protected slots:
    void actionOpenFile();
    void actionCloseFile();
    void actionSaveAs();
    void applyFilter();
};
#endif // MAINWINDOW_H
