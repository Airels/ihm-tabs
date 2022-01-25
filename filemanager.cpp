#include "filemanager.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QMessageBox>

FileManager::FileManager(QWidget * attachedWidget)
{
    this->attachedWidget = attachedWidget;
}

void FileManager::openFile(DataManager &var) {
    QFileDialog fileDialog;
    QString defaultSelection = this->acceptedFileTypes[1];
    QString filename = fileDialog.getOpenFileName(attachedWidget, "Open file", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), getAcceptedFileTypes(), &defaultSelection);

    QMessageBox::warning(attachedWidget, "File selected", filename, QMessageBox::Ok);
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
