#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QApplication>
#include <cstring>
#include <QFile>
#include <QWidget>
#include "datamanager.h"

class FileManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(FileManager)

public:
    const QString acceptedFileTypes[3] = {
        "All files (*.*)",
        "CSV File (*.csv)",
        "XML File (*.xml)"
    };
    FileManager(QWidget * attachedWidget);

protected slots:
    void openFile(DataManager *dataManager);
    void saveFile(QString filename, DataManager *cells);

private:
    QWidget * attachedWidget;

    QString getAcceptedFileTypes();
    bool parseCSVFile(QFile &file, QStandardItemModel * data);
    bool parseXMLFile(QFile &file, QStandardItemModel * data);
};

#endif // FILEMANAGER_H
