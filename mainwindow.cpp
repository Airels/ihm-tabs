#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include "activatefiltermanager.h"
#include <QDebug>
#include <QObject>
#include <QIcon>
#include <QCheckBox>
#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <float.h>

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
    activateFilterManager = nullptr;

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
    connect(ui->_applyFilterBtn, SIGNAL(clicked()), this, SLOT(applyFilter()));
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
        activateFilterManager = new ActivateFilterManager(dataManager, viewManager, ui->_activeFilter, ui->_applyFilterBtn);
        QStandardItemModel *model = dataManager->getCells();
        resetInterface();
        setEnabled(true);
        viewManager = new ViewManager(ui->_tableView, model);
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
    QDialog dialog(this);
    QFormLayout form(&dialog);
    form.addRow(new QLabel("Please give following values:"));
    // Value1
    QString rowStr = QString("Number of rows: ");
    QSpinBox *spinbox1 = new QSpinBox(&dialog);
    spinbox1->setMaximum(INT_MAX);
    spinbox1->setMinimum(0);
    form.addRow(rowStr, spinbox1);
    // Value2
    QString columnStr = QString("Number of columns: ");
    QSpinBox *spinbox2 = new QSpinBox(&dialog);
    spinbox2->setMaximum(INT_MAX);
    spinbox2->setMinimum(0);
    form.addRow(columnStr, spinbox2);

    // Value 3
    QString maxValueStr = QString("Maximal value (not required): ");
    QDoubleSpinBox *spinbox3 = new QDoubleSpinBox(&dialog);
    spinbox3->setMaximum(DBL_MAX);
    spinbox3->setMinimum(-DBL_MAX);
    form.addRow(maxValueStr, spinbox3);
    // Value 4
    QString minValueStr = QString("Minimal value (not required): ");
    QDoubleSpinBox *spinbox4 = new QDoubleSpinBox(&dialog);
    spinbox4->setMaximum(DBL_MAX);
    spinbox4->setMinimum(-DBL_MAX);
    form.addRow(minValueStr, spinbox4);
    // Add Cancel and OK button
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Process when OK button is clicked
    if (dialog.exec() == QDialog::Accepted) {
        resetInterface();
        int numberOfRows = (int) spinbox1->value();
        int numberOfColumns = (int) spinbox2->value();
        double maxValue = (double) spinbox3->value();
        double minValue = (double) spinbox4->value();
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
        viewManager = new ViewManager(ui->_tableView, model);
        ui->_tableView->setModel(viewManager->tableView()->model());
    }
}

void MainWindow::activateFilter() {
    if(ui->_treeFilter->currentItem()->childCount() > 0) return;
    int categoryIndex = ui->_treeFilter->indexOfTopLevelItem(ui->_treeFilter->currentItem()->parent());
    int toolIndex = ui->_treeFilter->currentIndex().row();
    qDebug() << "[USER ACTION] 'activated new filer from category " << categoryIndex << " and tool index " << toolIndex;
    activateFilterManager->setFilterName(ui->_treeFilter->currentItem()->text(0));
    activateFilterManager->handle(categoryIndex, toolIndex);
}

void MainWindow::applyFilter() {
    qDebug() << "[USER ACTION] button 'Apply' clicked";
    QModelIndexList model = viewManager->tableView()->selectionModel()->selectedIndexes();
    int categoryIndex = ui->_treeFilter->indexOfTopLevelItem(ui->_treeFilter->currentItem()->parent());
    int toolIndex = ui->_treeFilter->currentIndex().row();
    activateFilterManager->applyFilter(&model, categoryIndex, toolIndex);
}
