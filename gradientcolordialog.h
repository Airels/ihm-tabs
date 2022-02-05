#ifndef GRADIENTCOLORDIALOG_H
#define GRADIENTCOLORDIALOG_H

#include "ui_gradientcolordialog.h"

/**
 * @brief The GradientColorDialog class is the one in charge of the QDialog to handle the "gradient color" filter.
 * @author Eddy IKHLEF
 */
class GradientColorDialog : public QDialog, private Ui::GradientColorDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param parent it's parent QWidget.
     * @author Eddy IKHLEF
     */
    GradientColorDialog(QWidget *parent = nullptr);
    ~GradientColorDialog();
    QColor getSelectedColorMin();
    QColor getSelectedColorMax();

protected slots:
    void colorChangedMin();
    void colorChangedMax();
};

#endif // GRADIENTCOLORDIALOG_H
