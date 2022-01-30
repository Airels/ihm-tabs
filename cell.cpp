#include "cell.h"
#include <QDebug>

Cell::Cell(double value, QColor color) {
    this->setValue(value);
    this->setColor(color);
}

Cell::Cell(double value) {
    this->setValue(value);
    this->setColor(QColor(255, 255, 255));
}

Cell::~Cell() {

}

double Cell::getvalue() {
    return value;
}

void Cell::setValue(double value) {
    this->value = value;
    this->setText(QString::number(value));
}

QColor Cell::getColor() {
    return this->color;
}

void Cell::setColor(QColor color) {
    this->color = color;
    QBrush* brush = new QBrush(this->color);
    this->setBackground(*brush);
}

bool Cell::isUpdatable() {
    return this->updatable;
}
