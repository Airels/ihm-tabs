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
    /**
     * @brief getSelectedColorMin
     * @return the selected "minimum color" as a QColor.
     * @author Eddy IKHLEF
     */
    QColor getSelectedColorMin();
    /**
     * @brief getSelectedColorMax
     * @return the selected "maximum color" as a QColor.
     * @author Eddy IKHLEF
     */
    QColor getSelectedColorMax();

protected slots:
    /**
     * @brief colorChangedMin slot method called when the user interact with the elements that contains
     *        color values for the "minimum color" section in the ui.
     * @author Eddy IKHLEF
     */
    void colorChangedMin();
    /**
     * @brief colorChangedMax slot method called when the user interact with the elements that contains
     *        color values for the "maximum color" section in the ui.
     * @author Eddy IKHLEF
     */
    void colorChangedMax();
};

#endif // GRADIENTCOLORDIALOG_H
