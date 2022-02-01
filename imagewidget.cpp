#include "imagewidget.h"
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>
#include <QImageReader>
#include <QImage>
#include "mainwindow.h"

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    label->setMinimumSize(1, 1);
    // label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    this->image = new QImage(1, 1, QImage::Format::Format_RGB888);
}

void ImageWidget::setImage(QImage *image) {
    this->image = image;

    QPixmap pixmap = QPixmap::fromImage(*image);
    label->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void ImageWidget::resizeEvent(QResizeEvent *pQEvent) {
    QPixmap pixmap = QPixmap::fromImage(*image);
    label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    qDebug() << "Resize";
}
