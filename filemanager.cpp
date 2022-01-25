#include "filemanager.h"
#include "datamanager.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QtXml>

FileManager::FileManager(QWidget * attachedWidget)
{
    this->attachedWidget = attachedWidget;
}

bool FileManager::openFile(DataManager *dataManager) {
    if (dataManager == nullptr)
        dataManager = new DataManager();

    QFileDialog fileDialog;
    QString defaultSelection = this->acceptedFileTypes[1];
    QString filename = fileDialog.getOpenFileName(attachedWidget, "Open file", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), getAcceptedFileTypes(), &defaultSelection);

    if (filename == "") {
        delete dataManager;
        dataManager = nullptr;
        return false;
    }

    qDebug() << "File selected: " << filename;

    QFile file(filename);
    QStandardItemModel *data = dataManager->getCells();

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(attachedWidget, "Failed to open " + filename, "File " + filename + " could not be opened.", QMessageBox::Ok);
        delete dataManager;
        dataManager = nullptr;
        return false;
    }

    qDebug() << "File opened";

    if (filename.endsWith(".csv") || filename.endsWith(".CSV")) {
        qDebug() << "CSV File";
        if (!this->parseCSVFile(file, data)) {
            data->clear();
            return false;
        }
    } else if (filename.endsWith(".xml") || filename.endsWith(".XML")) {
        qDebug() << "XML File";
        if (!this->parseXMLFile(file, data)) {
            data->clear();
            return false;
        }
    } else {
        qDebug() << "Not a recognized format";
        QString msg = "We are unable to read '";
        msg.append(filename);
        msg.append("' file, due to its wrong file type.\n\n");
        msg.append("Accepted file types :\n");

        size_t size = sizeof acceptedFileTypes / sizeof(QString);
        for (size_t i = 1; i < size; i++) {
            qDebug() << i;
            msg.append("\t- ");
            msg.append(acceptedFileTypes[i]);
            msg.append("\n");
        }

        QMessageBox::warning(attachedWidget, "Wrong file format", msg, QMessageBox::Ok);
        delete dataManager;
        dataManager = nullptr;
        return false;
    }

    file.close();
    return true;
}

bool FileManager::saveFile(QString filename, DataManager *cells) {
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

bool FileManager::parseCSVFile(QFile &file, QStandardItemModel * data) {
    if (data == nullptr) {
        qDebug() << "Cannot parse CSV File: model pointer is null" << endl;
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
            qDebug() << "Cannot parse XML File: model pointer is null" << endl;
            exit(EXIT_FAILURE);
    }

    QFile *f = &file;
    QDomDocument xmlFile;
    xmlFile.setContent(f);

    QDomElement root = xmlFile.documentElement();
    QDomElement row = root.firstChildElement();

    while (!row.isNull()) {
        if (row.tagName() != "row") {
            qDebug("Cannot read XML file: wrong xml encoding (row element not found)");
            QMessageBox::critical(attachedWidget, "XML Parsing Error", "Error while reading XML file: required data is missing (expected row)", QMessageBox::Ok);
            return false;
        }

        QList<QStandardItem *> cells;
        QDomElement cell = row.firstChildElement();

        while (!cell.isNull()) {
            if (cell.tagName() != "cell") {
                qDebug("Cannot read XML file: wrong xml encoding (cell element not found)");
                QMessageBox::critical(attachedWidget, "XML Parsing Error", "Error while reading XML file: required data is missing (expected cell)", QMessageBox::Ok);
                return false;
            }

            bool ok(false);
            double value = cell.elementsByTagName("value").at(0).toElement().text().toDouble(&ok);

            if (!ok) {
                qDebug("Cannot read XML file: data contains non-numerical values"); // TODO
                QMessageBox::critical(attachedWidget, "XML Parsing Error", "Error while reading XML file: data contains non-numerical values", QMessageBox::Ok);
                return false;
            }

            QDomElement colors = cell.elementsByTagName("color").at(0).toElement();
            if (colors.isNull()) {
                qDebug("Cannot read XML file: wrong xml encoding (color element not found)"); // TODO
                QMessageBox::critical(attachedWidget, "XML Parsing Error", "Error while reading XML file: required data is missing (expected cell)", QMessageBox::Ok);
                return false;
            }

            int red, green, blue;

            ok = false;
            red = colors.elementsByTagName("red").at(0).toElement().text().toDouble(&ok);
            if (!ok || red < 0 || red > 255) {
                qDebug("Cannot read XML file: wrong xml encoding (red value)");
                QMessageBox::critical(attachedWidget, "XML Parsing Error", "Error while reading XML file: cannot resolve cell color (red value)", QMessageBox::Ok);
                return false;
            }

            ok = false;
            green = colors.elementsByTagName("green").at(0).toElement().text().toDouble(&ok);
            if (!ok || green < 0 || green > 255) {
                qDebug("Cannot read XML file: wrong xml encoding (green value)");
                QMessageBox::critical(attachedWidget, "XML Parsing Error", "Error while reading XML file: cannot resolve cell color (green value)", QMessageBox::Ok);
                return false;
            }

            ok = false;
            blue = colors.elementsByTagName("blue").at(0).toElement().text().toDouble(&ok);
            if (!ok || blue < 0 || blue > 255) {
                qDebug("Cannot read XML file: wrong xml encoding (blue value)");
                QMessageBox::critical(attachedWidget, "XML Parsing Error", "Error while reading XML file: cannot resolve cell color (blue value)", QMessageBox::Ok);
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
