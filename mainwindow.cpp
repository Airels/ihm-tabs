#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include "activatefiltermanager.h"
#include <QDebug>
#include <QObject>
#include <QIcon>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon.png"));
    initAttributes();
    initSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileManager;
    delete dataManager;
    delete viewManager;
    delete activateFilterManager;
}

void MainWindow::initAttributes() {
    dataManager = nullptr;
    fileManager = new FileManager(this);
    viewManager = new ViewManager(ui->_tableView);
    activateFilterManager = new ActivateFilterManager(ui->_activeFilter, ui->_applyFilterBtn);

    _actionOpenFile = ui->_menuFile->addAction("Open File");
    _actionCloseFile = ui->_menuFile->addAction("Close File");
    ui->_menuFile->addSeparator();
    _actionSaveAs = ui->_menuFile->addAction("Save As...");
    _actionExportAs = ui->_menuFile->addAction("Export Image As...");
    _actionGenerate = ui->_menuTools->addAction("Generate");

    _actionCloseFile->setEnabled(false);
    _actionSaveAs->setEnabled(false);
    _actionExportAs->setEnabled(false);
}

void MainWindow::initSignals() {
    connect(_actionOpenFile, SIGNAL(triggered()), this, SLOT(actionOpenFile()));
    connect(_actionCloseFile, SIGNAL(triggered()), this, SLOT(actionCloseFile()));
    connect(_actionSaveAs, SIGNAL(triggered()), this, SLOT(actionSaveAs()));
    connect(_actionExportAs, SIGNAL(triggered()), this, SLOT(actionExportAs()));
    connect(_actionGenerate, SIGNAL(triggered()), this, SLOT(actionGenerate()));
    connect(ui->_treeFilter,SIGNAL(itemClicked(QTreeWidgetItem*,int)), SLOT(activateFilter()));
}

void MainWindow::resetInterface() {
    //(qobject_cast<QStandardItemModel *>(ui->_tableView->model()))->setColumnCount(0);
    //(qobject_cast<QStandardItemModel *>(ui->_tableView->model()))->setRowCount(0);
    ui->_tableView->setModel(nullptr);
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
    if(dataManager != nullptr) dataManager = nullptr;
    if(fileManager->openFile(dataManager)) {
        QStandardItemModel *model = dataManager->getCells();
        resetInterface();
        setEnabled(true);
        viewManager->tableView()->setModel(model);
        ui->_tableView->setModel(viewManager->tableView()->model());
    }
}

void MainWindow::actionCloseFile() {
    qDebug() << "[USER ACTION] Close File";
    if(dataManager != nullptr) dataManager = nullptr;
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

void MainWindow::actionGenerate() {
    qDebug() << "[USER ACTION] Generate";
}

void MainWindow::activateFilter() {
    if(ui->_treeFilter->currentItem()->childCount() > 0) return;
    int categoryIndex = ui->_treeFilter->indexOfTopLevelItem(ui->_treeFilter->currentItem()->parent());
    int toolIndex = ui->_treeFilter->currentIndex().row();
    qDebug() << "[USER ACTION] 'activated new filer from category " << categoryIndex << " and tool index " << toolIndex;
    activateFilterManager->setFilterName(ui->_treeFilter->currentItem()->text(0));
    activateFilterManager->handle(categoryIndex, toolIndex);
    //test
    QVBoxLayout* _activeFilterLayout = new QVBoxLayout;
}

void MainWindow::applyFilter() {
    qDebug() << "[USER ACTION] button 'Apply' clicked";
}
