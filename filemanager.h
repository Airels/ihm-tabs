#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QApplication>
#include <cstring>
#include <QFile>
#include "datamanager.h"

class FileManager : public QObject
{
Q_OBJECT

public:
    const QString types[2] = {
        "CSV File (*.csv)",
        "XLS File (*.xls)"
    };
    FileManager();

protected slots:
    void openFile(DataManager &var);
    void saveFile(QString filename, DataManager cells);
};

#endif // FILEMANAGER_H
