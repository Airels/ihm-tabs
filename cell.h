#ifndef CELL_H
#define CELL_H
#include <QString>
#include <QColor>
#include <QApplication>
#include <QStandardItem>

class Cell: public QStandardItem
{

public:
    Cell(double value, QColor color);
    Cell(double value);
    ~Cell();

    double getvalue();
    void setValue(double value);
    QColor getColor();
    void setColor(QColor color);
    bool isUpdatable();
    // void setUpdatable(bool updatable);

private:
    double value;
    QColor color;
    const bool updatable = false;
};

#endif // CELL_H
