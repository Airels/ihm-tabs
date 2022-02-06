#ifndef FIXEDCOLORDIALOG_H
#define FIXEDCOLORDIALOG_H

#include "ui_fixedcolordialog.h"

/**
 * @brief The FixedColorDialog class is the one in charge of the QDialog to handle the "fixed color" filter.
 * @author Eddy IKHLEF
 */
class FixedColorDialog : public QDialog, private Ui::FixedColorDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param parent it's parent QWidget.
     * @author Eddy IKHLEF
     */
    FixedColorDialog(QWidget *parent = nullptr);
    ~FixedColorDialog();
    /**
     * @brief getSelectedColor
     * @return the selected color as a QColor.
     * @author Eddy IKHLEF
     */
    QColor getSelectedColor();

protected slots:
    /**
     * @brief colorChanged slot method called when the user interact with the elements that contains
     *        color values for the color section in the ui.
     * @author Eddy IKHLEF
     */
    void colorChanged();
};

#endif // FIXEDCOLORDIALOG_H
