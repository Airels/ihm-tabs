#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QApplication>
#include <cstring>
#include <QFile>
#include <QWidget>
#include "datamanager.h"

class FileManager
{
public:
    const QString acceptedFileTypes[3] = {
        "All files (*.*)",
        "CSV File (*.csv)",
        "XML File (*.xml)"
    };
    FileManager(QWidget * attachedWidget);
    bool openFile(DataManager *&dataManager);
    bool saveFile(QString filename, DataManager *cells);

private:
    QWidget * attachedWidget;

    QString getAcceptedFileTypes();
    bool parseCSVFile(QFile &file, QStandardItemModel * data);
    bool parseXMLFile(QFile &file, QStandardItemModel * data);
};

#endif // FILEMANAGER_H
