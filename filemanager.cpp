#include "filemanager.h"
#include "datamanager.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QtXml>
#include <QPixmap>

FileManager::FileManager(QWidget * attachedWidget)
{
    this->attachedWidget = attachedWidget;
}

bool FileManager::openFile(DataManager *&dataManager) {
    if (dataManager == nullptr)
        dataManager = new DataManager();

    QFileDialog fileDialog;
    QString defaultSelection = this->acceptedOpenFileTypes;
    QString filename = fileDialog.getOpenFileName(attachedWidget, "Open file", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), this->acceptedOpenFileTypes, &defaultSelection);

    if (filename == "")
        return false;

    qDebug() << "File selected: " << filename;

    QFile file(filename);
    QStandardItemModel *data = dataManager->getCells();

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(attachedWidget, "Failed to open " + filename, "File " + filename + " could not be opened.", QMessageBox::Ok);
        return false;
    }

    qDebug() << "File opened";

    if (filename.toLower().endsWith(".csv")) {
        qDebug() << "CSV File";
        if (!this->parseCSVFile(file, data)) {
            data->clear();
            return false;
        }
    } else if (filename.toLower().endsWith(".itabs")) {
        qDebug() << "ITabs File";
        if (!this->parseXMLFile(file, data)) {
            data->clear();
            return false;
        }
    } else {
        qDebug() << "Not a recognized format";
        QString msg = "We are unable to read '";
        msg.append(filename);
        msg.append("' file, due to its wrong file type.\n\n");

        QMessageBox::warning(attachedWidget, "Wrong file format", msg, QMessageBox::Ok);
        return false;
    }

    file.close();
    return true;
}

bool FileManager::saveFile(DataManager *dataManager) {
    const QStandardItemModel *cells = dataManager->getCells();
    QFileDialog fileDialog;
    QString defaultSelection = this->acceptedSaveFileTypes;
    QString filename = fileDialog.getSaveFileName(attachedWidget, "Save file", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), this->acceptedSaveFileTypes, &defaultSelection);

    if (filename == "")
        return false;

    qDebug() << filename;

    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(attachedWidget, "Failed to open " + filename, "File " + filename + " could not be opened.", QMessageBox::Ok);
        return false;
    }

    QTextStream fileIn(&file);
    QDomDocument xmlFile;

    QDomElement data = xmlFile.createElement("data");
    xmlFile.appendChild(data);

    int nbRows = cells->rowCount(), nbColumns = cells->columnCount();

    for (int row = 0; row < nbRows; row++) {
        QDomElement rowDom = xmlFile.createElement("row");
        data.appendChild(rowDom);

        for (int column = 0; column < nbColumns; column++) {
            Cell *cell = (Cell *) cells->item(row, column);
            QDomElement cellDom = xmlFile.createElement("cell");
            rowDom.appendChild(cellDom);

            QDomElement value = xmlFile.createElement("value");
            cellDom.appendChild(value);
            value.appendChild(xmlFile.createTextNode(QString::number(cell->getvalue())));

            QDomElement colorDom = xmlFile.createElement("color");
            cellDom.appendChild(colorDom);
            int r, g, b;
            cell->getColor().getRgb(&r, &g, &b);


            QDomElement redDom = xmlFile.createElement("red");
            colorDom.appendChild(redDom);
            redDom.appendChild(xmlFile.createTextNode(QString::number(r)));

            QDomElement greenDom = xmlFile.createElement("green");
            colorDom.appendChild(greenDom);
            greenDom.appendChild(xmlFile.createTextNode(QString::number(g)));

            QDomElement blueDom = xmlFile.createElement("blue");
            colorDom.appendChild(blueDom);
            blueDom.appendChild(xmlFile.createTextNode(QString::number(b)));
        }
    }

    fileIn << xmlFile.toString();
    file.close();

    return true;
}

bool FileManager::saveImage(const QImage *image) {
    if (image == nullptr) {
        qDebug() << "Cannot parse image file: image pointer is null";
        exit(EXIT_FAILURE);
    }

    QFileDialog fileDialog;
    QString defaultSelection = this->acceptedSaveImageTypes.split(";;")[0];
    QString filename = fileDialog.getSaveFileName(attachedWidget, "Save as image", QStandardPaths::writableLocation(QStandardPaths::PicturesLocation), this->acceptedSaveImageTypes, &defaultSelection);

    if (filename == "")
        return false;

    qDebug() << filename;

    if (!image->save(filename)) {
        QString msg = "An error occured while saving data as image.";
        QMessageBox::warning(attachedWidget, "Save as image failed", msg, QMessageBox::Ok);
        return false;
    } else {
        QString msg = "Image saved successfully!";
        QMessageBox::information(attachedWidget, "Image saved", msg, QMessageBox::Ok);
        return true;
    }
}

bool FileManager::parseCSVFile(QFile &file, QStandardItemModel * data) {
    if (data == nullptr) {
        qDebug() << "Cannot parse CSV File: model pointer is null";
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
            QMessageBox::critical(attachedWidget, "CSV Parsing Error", "Error while reading CSV File (no presence of valid separators)", QMessageBox::Ok);
            return false;
        }

        QList<QStandardItem *> cells;
        for (QString value : row) {
            bool ok(false);
            QStandardItem *cell = new Cell(value.toDouble(&ok));

            if (!ok) {
                QMessageBox::critical(attachedWidget, "CSV Parsing Error", "Error while reading CSV File (data contains non-numerical values)", QMessageBox::Ok);
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
            qDebug() << "ITabs File corrupted: model pointer is null";
            exit(EXIT_FAILURE);
    }

    QFile *f = &file;
    QDomDocument xmlFile;
    xmlFile.setContent(f);

    QDomElement root = xmlFile.documentElement();
    QDomElement row = root.firstChildElement();

    while (!row.isNull()) {
        if (row.tagName() != "row") {
            qDebug("ITabs File corrupted: wrong xml encoding (row element not found)");
            QMessageBox::critical(attachedWidget, "ITabs Parsing Error", "ITabs File corrupted: required data is missing (expected row)", QMessageBox::Ok);
            return false;
        }

        QList<QStandardItem *> cells;
        QDomElement cell = row.firstChildElement();

        while (!cell.isNull()) {
            if (cell.tagName() != "cell") {
                qDebug("Cannot read XML file: wrong xml encoding (cell element not found)");
                QMessageBox::critical(attachedWidget, "ITabs Parsing Error", "ITabs File corrupted: required data is missing (expected cell)", QMessageBox::Ok);
                return false;
            }

            bool ok(false);
            double value = cell.elementsByTagName("value").at(0).toElement().text().toDouble(&ok);

            if (!ok) {
                qDebug("Cannot read XML file: data contains non-numerical values"); // TODO
                QMessageBox::critical(attachedWidget, "ITabs Parsing Error", "ITabs File corrupted: data contains non-numerical values", QMessageBox::Ok);
                return false;
            }

            QDomElement colors = cell.elementsByTagName("color").at(0).toElement();
            if (colors.isNull()) {
                qDebug("Cannot read XML file: wrong xml encoding (color element not found)"); // TODO
                QMessageBox::critical(attachedWidget, "ITabs Parsing Error", "ITabs File corrupted: required data is missing (expected cell)", QMessageBox::Ok);
                return false;
            }

            int red, green, blue;

            ok = false;
            red = colors.elementsByTagName("red").at(0).toElement().text().toDouble(&ok);
            if (!ok || red < 0 || red > 255) {
                qDebug("Cannot read XML file: wrong xml encoding (red value)");
                QMessageBox::critical(attachedWidget, "ITabs Parsing Error", "ITabs File corrupted: cannot resolve cell color (red value)", QMessageBox::Ok);
                return false;
            }

            ok = false;
            green = colors.elementsByTagName("green").at(0).toElement().text().toDouble(&ok);
            if (!ok || green < 0 || green > 255) {
                qDebug("Cannot read XML file: wrong xml encoding (green value)");
                QMessageBox::critical(attachedWidget, "ITabs Parsing Error", "ITabs File corrupted: cannot resolve cell color (green value)", QMessageBox::Ok);
                return false;
            }

            ok = false;
            blue = colors.elementsByTagName("blue").at(0).toElement().text().toDouble(&ok);
            if (!ok || blue < 0 || blue > 255) {
                qDebug("Cannot read XML file: wrong xml encoding (blue value)");
                QMessageBox::critical(attachedWidget, "ITabs Parsing Error", "ITabs File corrupted: cannot resolve cell color (blue value)", QMessageBox::Ok);
                return false;
            }

            cells.append(new Cell(value, QColor(red, green, blue)));

            cell = cell.nextSiblingElement();
        }

        data->appendRow(cells);

        row = row.nextSiblingElement();
    }

    return true;
}
