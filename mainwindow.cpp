#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include "activatefiltermanager.h"
#include "generatedialog.h"
#include <QDebug>
#include <QObject>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << "mainWindowConstructor";
    dataManager = nullptr;
    viewManager = nullptr;
    fileManager = new FileManager(this);
    activateFilterManager = nullptr;
    ui->setupUi(this);
    qDebug() << "setupUI";
    this->setWindowIcon(QIcon(":/icon.png"));
    initAttributes();
    initSignals();

    this->imageWidget = new ImageWidget(this);
    ui->_tabWidget->addTab(this->imageWidget, "Image Representation");
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
    qDebug() << "init attributes";


    _actionOpenFile = ui->_menuFile->addAction("Open File");
    _actionCloseFile = ui->_menuFile->addAction("Close File");
    _actionSaveAs = ui->_menuFile->addAction("Save File");
    ui->_menuFile->addSeparator();
    _actionExportAs = ui->_menuFile->addAction("Export As Image");
    _actionGenerate = ui->_menuTools->addAction("Generate");
    ui->_menuTools->addSeparator();

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
    connect(ui->_applyFilterBtn, SIGNAL(clicked()), this, SLOT(applyFilter()));
}

void MainWindow::initViewManager(QStandardItemModel *model)
{
    if (model == nullptr){
        qDebug() << "model not yet initialized";
        return;
    }
    viewManager = new ViewManager(ui->_tableView, model);
    imageWidget->setImage(viewManager->getImage());
    connect(viewManager, SIGNAL(sortRequested(int, Qt::SortOrder)), this, SLOT(sortModel(int, Qt::SortOrder)));
    updateImage(); //maybe not useful
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

void MainWindow::updateImage()
{
    viewManager->updateImage();
    imageWidget->reload();
}

void MainWindow::setEnabled(bool value) {
    ui->_tabWidget->setEnabled(value);
    ui->_activeFilter->setEnabled(value);
    ui->_treeFilter->setEnabled(value);
    ui->_checkAll->setEnabled(value);
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
        activateFilterManager = new ActivateFilterManager(dataManager, ui->_activeFilter, ui->_applyFilterBtn);
        QStandardItemModel *model = dataManager->getCells();
        resetInterface();
        setEnabled(true);
        initViewManager(model);
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
    if(fileManager->saveFile(dataManager)) {
        qDebug() << "FILE SAVED";
    }
}

void MainWindow::actionExportAs() {
    qDebug() << "[USER ACTION] Export Image As";
    FileManager fileManager(this);
    viewManager->updateImage();
    if(fileManager.saveImage(viewManager->getImage())) {
        qDebug() << "EXPORTED SUCCESSFULLY";
    }
}

void MainWindow::actionGenerate() {
    qDebug() << "[USER ACTION] Generate";
    GenerateDialog* dialog = new GenerateDialog();
    // Process when OK button is clicked
    if (dialog->exec() == QDialog::Accepted) {
        resetInterface();
        int numberOfRows = dialog->getNumberOfRows();
        int numberOfColumns = dialog->getNumberOfCols();
        double maxValue = dialog->getMaxValue();
        double minValue = dialog->getMinValue();
        bool enable = true;
        qDebug() << "[values]" << numberOfRows << numberOfColumns << maxValue << minValue;
        dataManager = new DataManager();
        if(maxValue == 0 && minValue == 0 ){
            dataManager->generateRandomValue(numberOfRows,numberOfColumns);
        }else{
            enable = dataManager->generateRandomValue(numberOfRows,numberOfColumns,minValue,maxValue,this);
        }
        QStandardItemModel *model = dataManager->getCells();
        setEnabled(enable);
        activateFilterManager = new ActivateFilterManager(dataManager, ui->_activeFilter, ui->_applyFilterBtn);
        initViewManager(model);
    }
}

void MainWindow::activateFilter() {
    //if(ui->_treeFilter->currentItem()->childCount() > 0) return; //add to only allows filters inside filters sections
    int categoryIndex = ui->_treeFilter->indexOfTopLevelItem(ui->_treeFilter->currentItem()->parent());
    int toolIndex = ui->_treeFilter->currentIndex().row();
    qDebug() << "[USER ACTION] 'activated new filer from category " << categoryIndex << " and tool index " << toolIndex;
    activateFilterManager->setFilterName(ui->_treeFilter->currentItem()->text(0));
    activateFilterManager->handle(categoryIndex, toolIndex);
}

void MainWindow::applyFilter() {
    qDebug() << "[USER ACTION] button 'Apply' clicked";
    if(ui->_checkAll->isChecked()) viewManager->getTableView()->selectAll();
    QModelIndexList model = viewManager->getTableView()->selectionModel()->selectedIndexes();
    int categoryIndex = ui->_treeFilter->indexOfTopLevelItem(ui->_treeFilter->currentItem()->parent());
    int toolIndex = ui->_treeFilter->currentIndex().row();
    activateFilterManager->applyFilter(&model, categoryIndex, toolIndex);
    updateImage();
}

void MainWindow::sortModel(int column, Qt::SortOrder order)
{
    qDebug() << "[USER ACTION] sort request on column" << column << "in order" << order;
    if (dataManager != nullptr){
        dataManager->sort_model(column, order);
    }
    updateImage();
}
