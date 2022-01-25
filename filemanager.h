#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QApplication>
#include <cstring>
#include <QFile>
#include <QWidget>
#include "datamanager.h"

class FileManager : public QObject
{
Q_OBJECT

public:
    const QString acceptedFileTypes[3] = {
        "All files (*.*)",
        "CSV File (*.csv)",
        "XML File (*.xml)"
    };
    FileManager(QWidget * attachedWidget);

protected slots:
    void openFile(DataManager &var);
    void saveFile(QString filename, DataManager cells);

private:
    QWidget * attachedWidget;

    QString getAcceptedFileTypes();
    void parseCSVFile(QFile &file, QStandardItemModel * data);
    void parseXMLFile(QFile &file, QStandardItemModel * data);
};

#endif // FILEMANAGER_H
