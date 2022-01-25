#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //instantiate attributes
    dataManager = nullptr;
    fileManager = new FileManager(this);
    viewManager = new ViewManager(ui->_tableView);
    //_menu children
    _actionOpenFile = ui->_menuFile->addAction("Open File");
    _actionCloseFile = ui->_menuFile->addAction("Close File");
    ui->_menuFile->addSeparator();
    _actionSaveAs = ui->_menuFile->addAction("Save As...");
    _actionExportAs = ui->_menuFile->addAction("Export Image As...");
    _actionCloseFile->setEnabled(false);
    _actionSaveAs->setEnabled(false);
    _actionExportAs->setEnabled(false);
    //slots
    connect(_actionOpenFile, SIGNAL(triggered()), this, SLOT(actionOpenFile()));
    connect(_actionCloseFile, SIGNAL(triggered()), this, SLOT(actionCloseFile()));
    connect(_actionSaveAs, SIGNAL(triggered()), this, SLOT(actionSaveAs()));
    connect(_actionExportAs, SIGNAL(triggered()), this, SLOT(actionExportAs()));
    connect(ui->_treeFilter,SIGNAL(itemClicked(QTreeWidgetItem*,int)), SLOT(activateFilter()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileManager;
    delete dataManager;
    delete viewManager;
}

void MainWindow::resetInterface() {
    ui->_tabWidget->setCurrentIndex(0);
    ui->_treeFilter->collapseAll();
    ui->_activeFilter->setTitle("");
    for(QObject *child : ui->_activeFilter->children()) {
        child->deleteLater();
    }
}

void MainWindow::setEnabled(bool value) {
    ui->_tabWidget->setEnabled(value);
    ui->_activeFilter->setEnabled(value);
    ui->_treeFilter->setEnabled(value);
    _actionCloseFile->setEnabled(value);
    _actionSaveAs->setEnabled(value);
    _actionExportAs->setEnabled(value);
    if(!value) ui->_applyFilterBtn->setEnabled(value);
}

/* SLOTS */
void MainWindow::actionOpenFile() {
    qDebug() << "[USER ACTION] Open File";
    //FileManager fileManager(this);
    if(fileManager->openFile(dataManager)) {
        QStandardItemModel *model = dataManager->getCells();
        viewManager->tableView()->setModel(model);
        //viewManager->tableView()->update();
        setEnabled(true);
        resetInterface();
    }
}

void MainWindow::actionCloseFile() {
    qDebug() << "[USER ACTION] Close File";
    setEnabled(false);
    resetInterface();
}

void MainWindow::actionSaveAs() {
    qDebug() << "[USER ACTION] Save As";
    FileManager fileManager(this);
    if(fileManager.saveFile(dataManager)) {
        qDebug() << "FILE SAVED"; // TODO
    }
}

void MainWindow::actionExportAs() {
    qDebug() << "[USER ACTION] Export Image As";
}

void MainWindow::activateFilter() {
    if(ui->_treeFilter->currentItem()->childCount() > 0) return;
    int categoryIndex = ui->_treeFilter->indexOfTopLevelItem(ui->_treeFilter->currentItem()->parent());
    int toolIndex = ui->_treeFilter->currentIndex().row();
    qDebug() << "[USER ACTION] 'activated new filer from category " << categoryIndex << " and tool index " << toolIndex;
    //TODO with the given values, connect to the filter tool and connect to the corresponding slot
    disconnect(ui->_applyFilterBtn, SIGNAL(clicked()));
    //connect(ui->_applyFilterBtn, SIGNAL(clicked()), this, SLOT(applyFilter()));
    ui->_applyFilterBtn->setEnabled(true);
}

void MainWindow::applyFilter() {
    qDebug() << "[USER ACTION] button 'Apply' clicked";
}
