#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QApplication>
#include <cstring>
#include <QFile>
#include <QWidget>
#include "datamanager.h"

/**
 * @brief The FileManager class, handling I/O from the disk to import or export files
 * @author VIZCAINO Yohan
 */
class FileManager
{
public:
    /**
     * @brief acceptedOpenFileTypes A QString who dictates what types of files is accepted to be opened
     * @author VIZCAINO Yohan
     */
    const QString acceptedOpenFileTypes = "CSV/ITabs File (*.csv *.itabs)";

    /**
     * @brief acceptedSaveFileTypes A QString who dictates what types of files is accepted to save data into
     * @author VIZCAINO Yohan
     */
    const QString acceptedSaveFileTypes = "ITabs File (*.itabs)";

    /**
     * @brief acceptedSaveImageTypes A QString who dictates what types of images could be used to save pixel-representation of input data
     * @author VIZCAINO Yohan
     */
    const QString acceptedSaveImageTypes = "Bitmap Image (*.bmp);;PNG Image (*.png);;JPG Image (*.jpg)";


    /**
     * @brief FileManager Builder of the class
     * @param attachedWidget The parent widget, who invoke the class
     * @author VIZCAINO Yohan
     */
    FileManager(QWidget * attachedWidget);

    /**
     * @brief openFile to open a file dialog, then load selected file data into the given pointer
     * @param dataManager Pointer of a DataManager, where datas need to be stored (if the pointer is null, a newly pointer will be created)
     * @return bool true if a file opened successfully, false otherwise
     * @author VIZCAINO Yohan
     */
    bool openFile(DataManager *&dataManager);

    /**
     * @brief saveFile to open a file dialog, then save given data into selected file
     * @param dataManager Pointer of the data to save
     * @return bool true if data saved successfully, false otherwise
     * @author VIZCAINO Yohan
     */
    bool saveFile(DataManager *dataManager);

    /**
     * @brief saveImage to open a file dialog, then save given image into selected
     * @param image Pointer to the QImage to save
     * @return bool true if image saved successfully, false otherwise
     * @author VIZCAINO Yohan
     */
    bool saveImage(const QImage *image);


private:
    /**
     * @brief attachedWidged The parent of the class, given in the builder
     */
    QWidget * attachedWidget;

    /**
     * @brief parseCSVFile parse data of given file in CSV format into data readable by the application
     * @param file File to parse
     * @param data Pointer of the data-memory representation to create
     * @return bool true if parse was successful, false otherwise
     * @author VIZCAINO Yohan
     */
    bool parseCSVFile(QFile &file, QStandardItemModel * data);

    /**
     * @brief parseXMLFile parse data of given file in XML format into data readable by the application
     * @param file File to parse
     * @param data Pointer of the data-memory representation to create
     * @return bool true if parse was successful, false otherwise
     * @author VIZCAINO Yohan
     */
    bool parseXMLFile(QFile &file, QStandardItemModel * data);
};

#endif // FILEMANAGER_H
