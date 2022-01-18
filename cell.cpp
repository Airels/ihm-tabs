#include "cell.h"

Cell::Cell(QString text, QColor color) {
    this->text = text;
    this->color = color;
}

Cell::Cell(QString text) {
    this->text = text;
    this->color = QColor(255, 255, 255);
}

Cell::~Cell() {

}

QString Cell::getText() {
    return text;
}

void Cell::setText(QString text) {
    this->text = text;
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
