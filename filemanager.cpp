#include "filemanager.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QMessageBox>

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

    QMessageBox::warning(attachedWidget, "File selected", filename, QMessageBox::Ok);

    const QFile &file = QFile(filename);
    QStandardItemModel *data = dataManager->getCells();

    if (filename.endsWith(".csv") || filename.endsWith(".CSV")) {
        this->parseCSVFile(file, data);
    } else if (filename.endsWith(".xml") || filename.endsWith(".XML")) {
        this->parseXMLFile(file, data);
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

void FileManager::parseCSVFile(const QFile &file, QStandardItemModel * data) {
    QMessageBox::warning(attachedWidget, "File selected", "CSV FILE", QMessageBox::Ok);
    exit(501);
}

void FileManager::parseXMLFile(const QFile &file, QStandardItemModel * data) {
    QMessageBox::warning(attachedWidget, "File selected", "XML FILE", QMessageBox::Ok);
    exit(501);
}
