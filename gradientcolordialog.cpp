#include "gradientcolordialog.h"

GradientColorDialog::GradientColorDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    //Connect
    connect(_hueSlider_min, &QSlider::valueChanged, this, &GradientColorDialog::colorChangedMin);
    connect(_saturationSlider_min, &QSlider::valueChanged, this, &GradientColorDialog::colorChangedMin);
    connect(_valueSlider_min, &QSlider::valueChanged, this, &GradientColorDialog::colorChangedMin);
    connect(_hueSlider_max, &QSlider::valueChanged, this, &GradientColorDialog::colorChangedMax);
    connect(_saturationSlider_max, &QSlider::valueChanged, this, &GradientColorDialog::colorChangedMax);
    connect(_valueSlider_max, &QSlider::valueChanged, this, &GradientColorDialog::colorChangedMax);

    //Set color
    int value = 255;
    _hueSlider_min->setValue(0);
    _saturationSlider_min->setValue(value/2);
    _valueSlider_min->setValue(value/2);
    _hueSlider_max->setValue(value);
    _saturationSlider_max->setValue(value/2);
    _valueSlider_max->setValue(value/2);
    colorChangedMin();
    colorChangedMax();
}

GradientColorDialog::~GradientColorDialog()
{
}

void GradientColorDialog::colorChangedMin() {
    QColor color;
    color.setHsv(_hueSlider_min->value(), _saturationSlider_min->value(), _valueSlider_min->value());
    QPalette pal;
    pal.setColor(QPalette::Window, color);
    _colorFrame_min->setPalette(pal);
}
void GradientColorDialog::colorChangedMax() {
    QColor color;
    color.setHsv(_hueSlider_max->value(), _saturationSlider_max->value(), _valueSlider_max->value());
    QPalette pal;
    pal.setColor(QPalette::Window, color);
    _colorFrame_max->setPalette(pal);
}

QColor GradientColorDialog::getSelectedColorMin() {
    QColor selectedColor;
    selectedColor.setHsv(_hueSlider_min->value(), _saturationSlider_min->value(), _valueSlider_min->value());
    return selectedColor;
}

QColor GradientColorDialog::getSelectedColorMax() {
    QColor selectedColor;
    selectedColor.setHsv(_hueSlider_max->value(), _saturationSlider_max->value(), _valueSlider_max->value());
    return selectedColor;
}
