#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //_menu children
    QAction* _actionOpenFile = ui->_menuFile->addAction("Open File");
    QAction* _actionCloseFile = ui->_menuFile->addAction("Close File");
    ui->_menuFile->addSeparator();
    QAction* _actionSaveAs = ui->_menuFile->addAction("Save As");
    //slots
    connect(_actionOpenFile, SIGNAL(triggered()), this, SLOT(actionOpenFile()));
    connect(_actionCloseFile, SIGNAL(triggered()), this, SLOT(actionCloseFile()));
    connect(_actionSaveAs, SIGNAL(triggered()), this, SLOT(actionSaveAs()));
    connect(ui->_applyFilterBtn, SIGNAL(clicked()), this, SLOT(applyFilter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::actionOpenFile() {
    qDebug() << "[USER ACTION] Open File";
}

void MainWindow::actionCloseFile() {
    qDebug() << "[USER ACTION] Close File";
}

void MainWindow::actionSaveAs() {
    qDebug() << "[USER ACTION] Save As";
}

void MainWindow::applyFilter() {
    qDebug() << "[USER ACTION] button 'Apply' clicked";
}
