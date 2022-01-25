#include "filemanager.h"
#include "datamanager.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>

FileManager::FileManager(QWidget * attachedWidget)
{
    this->attachedWidget = attachedWidget;
}

bool FileManager::openFile(DataManager *&dataManager) {
    if (dataManager == nullptr)
        dataManager = new DataManager();

    QFileDialog fileDialog;
    QString defaultSelection = this->acceptedFileTypes[1];
    QString filename = fileDialog.getOpenFileName(attachedWidget, "Open file", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), getAcceptedFileTypes(), &defaultSelection);

    if (filename == "") {
        delete dataManager;
        dataManager = nullptr;
        return false;
    }

    qDebug() << "File selected: " << filename;

    QFile file(filename);
    QStandardItemModel *data = dataManager->getCells();

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(attachedWidget, "Failed to open " + filename, "File " + filename + " could not be opened.", QMessageBox::Ok);
        delete dataManager;
        dataManager = nullptr;
        return false;
    }

    qDebug() << "File opened";

    if (filename.endsWith(".csv") || filename.endsWith(".CSV")) {
        qDebug() << "CSV File";
        if (!this->parseCSVFile(file, data)) {
            data->clear();
            return false;
        }
    } else if (filename.endsWith(".xml") || filename.endsWith(".XML")) {
        qDebug() << "XML File";
        if (!this->parseXMLFile(file, data)) {
            data->clear();
            return false;
        }
    } else {
        qDebug() << "Not a recognized format";
        QString msg = "We are unable to read '";
        msg.append(filename);
        msg.append("' file, due to its wrong file type.\n\n");
        msg.append("Accepted file types :\n");

        size_t size = sizeof acceptedFileTypes / sizeof(QString);
        for (size_t i = 1; i < size; i++) {
            qDebug() << i;
            msg.append("\t- ");
            msg.append(acceptedFileTypes[i]);
            msg.append("\n");
        }

        QMessageBox::warning(attachedWidget, "Wrong file format", msg, QMessageBox::Ok);
        delete dataManager;
        dataManager = nullptr;
        return false;
    }

    return true;
}

bool FileManager::saveFile(QString filename, DataManager *cells) {
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

    exit(501);
}
