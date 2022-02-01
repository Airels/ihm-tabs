#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include "ui_imagewidget.h"

class ImageWidget : public QWidget, private Ui::ImageWidget
{
    Q_OBJECT

private:
    QImage *image = nullptr;

public:
    explicit ImageWidget(QWidget *parent = nullptr);
    void setImage(QImage *image);

protected:
    virtual void resizeEvent(QResizeEvent *pQEvent);
};

#endif // IMAGEWIDGET_H
