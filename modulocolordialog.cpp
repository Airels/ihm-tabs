#include "modulocolordialog.h"

ModuloColorDialog::ModuloColorDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    //Connect
    connect(_hueSlider, &QSlider::valueChanged, this, &ModuloColorDialog::colorChanged);
    connect(_saturationSlider, &QSlider::valueChanged, this, &ModuloColorDialog::colorChanged);
    connect(_valueSlider, &QSlider::valueChanged, this, &ModuloColorDialog::colorChanged);

    //Set color
    int value = 255;
    _hueSlider->setValue(value/2);
    _saturationSlider->setValue(value/2);
    _valueSlider->setValue(value/2);
    colorChanged();


}

ModuloColorDialog::~ModuloColorDialog()
{
}

void ModuloColorDialog::colorChanged() {
    QColor color;
    color.setHsv(_hueSlider->value(), _saturationSlider->value(), _valueSlider->value());
    QPalette pal;
    pal.setColor(QPalette::Window, color);
    _colorFrame->setPalette(pal);
}

QColor ModuloColorDialog::getSelectedColor() {
    QColor selectedColor;
    selectedColor.setHsv(_hueSlider->value(), _saturationSlider->value(), _valueSlider->value());
    return selectedColor;
}

int ModuloColorDialog::getSelectedValue() {
    return _moduloBox->value();
}
