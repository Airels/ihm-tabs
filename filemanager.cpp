#include "filemanager.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>

FileManager::FileManager(QWidget * attachedWidget)
{
    this->attachedWidget = attachedWidget;
}

void FileManager::openFile(DataManager *dataManager) {
    if (dataManager == nullptr)
        dataManager = new DataManager();

    QFileDialog fileDialog;
    QString defaultSelection = this->acceptedFileTypes[1];
    QString filename = fileDialog.getOpenFileName(attachedWidget, "Open file", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), getAcceptedFileTypes(), &defaultSelection);

    QMessageBox::information(attachedWidget, "File selected", filename, QMessageBox::Ok);

    QFile file(filename);
    QStandardItemModel *data = dataManager->getCells();

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(attachedWidget, "Failed to open " + filename, "File " + filename + " could not be opened.", QMessageBox::Ok);
        return;
    }

    if (filename.endsWith(".csv") || filename.endsWith(".CSV")) {
        if (!this->parseCSVFile(file, data))
            data->clear();
    } else if (filename.endsWith(".xml") || filename.endsWith(".XML")) {
        if (!this->parseXMLFile(file, data))
            data->clear();
    } else {
        QString msg = "We are unable to read " + filename + " file, due to its wrong file type.\n";
        msg +=  "Accepted file types :\n";

        for (unsigned long long i = 1; i < sizeof acceptedFileTypes; i++) {
            msg += acceptedFileTypes[i] + "\n";
        }

        QMessageBox::warning(attachedWidget, "Wrong file format", msg, QMessageBox::Ok);
    }
}

void FileManager::saveFile(QString filename, DataManager cells) {
    exit(501);
}

QString FileManager::getAcceptedFileTypes() {
    QString res = "";
    QString token = ";;";

    for (QString str : this->acceptedFileTypes) {
        res += str + token;
    }

    return res;
}

bool FileManager::parseCSVFile(QFile &file, QStandardItemModel * data) {
    if (data == nullptr) {
        qDebug() << "Cannot parse CSV File: model pointer is null" << endl;
        exit(EXIT_FAILURE);
    }

    QMessageBox::information(attachedWidget, "File selected", "CSV FILE", QMessageBox::Ok);

    QTextStream in(&file);
    QString line;

    while (in.readLineInto(&line)) {
        QStringList row;
        if (line.contains(";"))
            row = line.split(";");
        else if (line.contains(","))
            row = line.split(",");
        else {
            QMessageBox::critical(attachedWidget, "CSV Parsing Error", "Error while parsing CSV File (no presence of valid separators)", QMessageBox::Ok);
            return false;
        }

        QList<QStandardItem *> cells;
        for (QString value : row) {
            bool ok(false);
            QStandardItem *cell = new Cell(value.toDouble(&ok));

            if (!ok) {
                QMessageBox::critical(attachedWidget, "CSV Parsing Error", "Error while parsing CSV File (data contains non-numerical values)", QMessageBox::Ok);
                return false;
            }
            cells.append(cell);
        }

        data->appendRow(cells);
    }

    return true;
}

bool FileManager::parseXMLFile(QFile &file, QStandardItemModel * data) {
    if (data == nullptr) {
            qDebug() << "Cannot parse XML File: model pointer is null" << endl;
            exit(EXIT_FAILURE);
    }

    QMessageBox::information(attachedWidget, "File selected", "XML FILE", QMessageBox::Ok);

    exit(501);
}
