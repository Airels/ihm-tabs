#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include "ui_imagewidget.h"

/**
 * @brief The ImageWidget class, used for having possibility to show images to the user
 * @author VIZCAINO Yohan
 */
class ImageWidget : public QWidget, private Ui::ImageWidget
{
    Q_OBJECT

private:
    /**
     * @brief image The image pointer to show
     */
    QImage *image = nullptr;

public:
    /**
     * @brief ImageWidget builder of the class
     * @param parent The parent widget
     */
    explicit ImageWidget(QWidget *parent = nullptr);

    /**
     * @brief setImage set a new image to show
     * @param image the image to show
     */
    void setImage(QImage *image);

    /**
     * @brief reload Updating the previously given image, used to resize the picture to fit the parent for example
     */
    void reload();

protected:
    /**
     * @brief resizeEvent Event called when the widget is resized
     * @param pQEvent
     */
    virtual void resizeEvent(QResizeEvent *pQEvent);
};

#endif // IMAGEWIDGET_H
