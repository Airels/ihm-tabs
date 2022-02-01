#include "fixedcolordialog.h"
#include <QColor>
#include <QPalette>
#include <QDebug>


FixedColorDialog::FixedColorDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    //Connect
    connect(_hueSlider, &QSlider::valueChanged, this, &FixedColorDialog::colorChanged);
    connect(_saturationSlider, &QSlider::valueChanged, this, &FixedColorDialog::colorChanged);
    connect(_valueSlider, &QSlider::valueChanged, this, &FixedColorDialog::colorChanged);

    //Set color
    int value = 255;
    _hueSlider->setValue(value/2);
    _saturationSlider->setValue(value/2);
    _valueSlider->setValue(value/2);
    colorChanged();


}

FixedColorDialog::~FixedColorDialog()
{
}

void FixedColorDialog::colorChanged() {
    QColor color;
    color.setHsv(_hueSlider->value(), _saturationSlider->value(), _valueSlider->value());
    QPalette pal;
    pal.setColor(QPalette::Window, color);
    _colorFrame->setPalette(pal);
}

QColor FixedColorDialog::getSelectedColor() {
    QColor selectedColor;
    selectedColor.setHsv(_hueSlider->value(), _saturationSlider->value(), _valueSlider->value());
    return selectedColor;
}

