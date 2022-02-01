#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include "ui_imagewidget.h"

class ImageWidget : public QWidget, private Ui::ImageWidget
{
    Q_OBJECT

public:
    explicit ImageWidget(QWidget *parent = nullptr);
};

#endif // IMAGEWIDGET_H
