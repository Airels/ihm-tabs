#ifndef CELL_H
#define CELL_H
#include <QString>
#include <QColor>

class Cell
{

public:
    Cell(QString text, QColor color);
    Cell(QString text);
    ~Cell();

    QString getText();
    void setText(QString text);
    QColor getColor();
    void setColor(QColor color);
    bool isUpdatable();
    // void setUpdatable(bool updatable);

private:
    QString text;
    QColor color;
    const bool updatable = false;
};

#endif // CELL_H