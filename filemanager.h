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
    const QString acceptedOpenFileTypes = "CSV/ITabs File (*.csv *.itabs)";
    const QString acceptedSaveFileTypes = "ITabs File (*.itabs)";
    const QString acceptedSaveImageTypes = "Bitmap (*.bmp);;PNG Image (*.png);;JPG Image (*.jpg)";

    FileManager(QWidget * attachedWidget);
    bool openFile(DataManager *&dataManager);
    bool saveFile(DataManager *dataManager);
    bool saveImage(const QImage *image);

private:
    QWidget * attachedWidget;
    bool parseCSVFile(QFile &file, QStandardItemModel * data);
    bool parseXMLFile(QFile &file, QStandardItemModel * data);
};

#endif // FILEMANAGER_H
