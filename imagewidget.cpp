#include "imagewidget.h"
#include <QLabel>
#include <QDebug>
#include <QResizeEvent>
#include <QImageReader>
#include <QImage>

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    label->setMinimumSize(1, 1);
}

void ImageWidget::setImage(const QString filename) {
    // this->img = QPixmap(filename);
    QImageReader reader(filename);
    image = reader.read();

    QPixmap pixmap = QPixmap::fromImage(image);
    label->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void ImageWidget::resizeEvent(QResizeEvent *pQEvent) {
    QPixmap pixmap = QPixmap::fromImage(image);
    label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}
