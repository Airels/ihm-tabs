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
        "CSV File (*.csv)",
        "XML File (*.xml)",
        "All files (*.*)"
    };
    FileManager(QWidget * attachedWidget);

protected slots:
    void openFile(DataManager &var);
    void saveFile(QString filename, DataManager cells);

private:
    QWidget * attachedWidget;
    QString getAcceptedFileTypes();
};

#endif // FILEMANAGER_H
