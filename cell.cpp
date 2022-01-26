#include "cell.h"

Cell::Cell(double value, QColor color) {
    this->value = value;
    this->color = color;
    this->setText(QString::number(value));
    this->setColor(color);
}

Cell::Cell(double value) {
    this->value = value;
    this->color = QColor(255, 255, 255);
    this->setText(QString::number(value));
    this->setColor(this->color);
}

Cell::~Cell() {

}

double Cell::getvalue() {
    return value;
}

void Cell::setValue(double value) {
    this->value = value;
}

QColor Cell::getColor() {
    return this->color;
}

void Cell::setColor(QColor color) {
    this->color = color;
}

bool Cell::isUpdatable() {
    return this->updatable;
}
