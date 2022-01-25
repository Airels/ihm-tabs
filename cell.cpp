#include "cell.h"

Cell::Cell(double value, QColor color) {
    this->value = value;
    this->color = color;
}

Cell::Cell(double value) {
    this->value = value;
    this->color = QColor(255, 255, 255);
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
