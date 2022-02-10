#include "conditionalcolordialog.h"

ConditionalColorDialog::ConditionalColorDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    //Connect
    connect(_hueSlider_min, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedMin);
    connect(_saturationSlider_min, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedMin);
    connect(_valueSlider_min, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedMin);
    connect(_hueSlider_equal, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedEqual);
    connect(_saturationSlider_equal, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedEqual);
    connect(_valueSlider_equal, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedEqual);
    connect(_hueSlider_max, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedMax);
    connect(_saturationSlider_max, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedMax);
    connect(_valueSlider_max, &QSlider::valueChanged, this, &ConditionalColorDialog::colorChangedMax);

    //Set color
    int value = 255;
    _hueSlider_min->setValue(0);
    _saturationSlider_min->setValue(value/4);
    _valueSlider_min->setValue(value/4);
    _hueSlider_equal->setValue(value);
    _saturationSlider_equal->setValue(value/2);
    _valueSlider_equal->setValue(value/2);
    _hueSlider_max->setValue(value);
    _saturationSlider_max->setValue(value);
    _valueSlider_max->setValue(value);
    colorChangedMin();
    colorChangedEqual();
    colorChangedMax();
}

ConditionalColorDialog::~ConditionalColorDialog()
{
}

void ConditionalColorDialog::colorChangedMin() {
    QColor color;
    color.setHsv(_hueSlider_min->value(), _saturationSlider_min->value(), _valueSlider_min->value());
    QPalette pal;
    pal.setColor(QPalette::Window, color);
    _colorFrame_min->setPalette(pal);
}

void ConditionalColorDialog::colorChangedEqual() {
    QColor color;
    color.setHsv(_hueSlider_equal->value(), _saturationSlider_equal->value(), _valueSlider_equal->value());
    QPalette pal;
    pal.setColor(QPalette::Window, color);
    _colorFrame_equal->setPalette(pal);
}

void ConditionalColorDialog::colorChangedMax() {
    QColor color;
    color.setHsv(_hueSlider_max->value(), _saturationSlider_max->value(), _valueSlider_max->value());
    QPalette pal;
    pal.setColor(QPalette::Window, color);
    _colorFrame_max->setPalette(pal);
}

QColor ConditionalColorDialog::getSelectedColorMin() {
    QColor selectedColor;
    selectedColor.setHsv(_hueSlider_min->value(), _saturationSlider_min->value(), _valueSlider_min->value());
    return selectedColor;
}

QColor ConditionalColorDialog::getSelectedColorEqual() {
    QColor selectedColor;
    selectedColor.setHsv(_hueSlider_equal->value(), _saturationSlider_equal->value(), _valueSlider_equal->value());
    return selectedColor;
}

QColor ConditionalColorDialog::getSelectedColorMax() {
    QColor selectedColor;
    selectedColor.setHsv(_hueSlider_max->value(), _saturationSlider_max->value(), _valueSlider_max->value());
    return selectedColor;
}

double ConditionalColorDialog::getSelectedValue() {
    return _valueBox->value();
}
