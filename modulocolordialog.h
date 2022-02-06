#ifndef MODULOCOLORDIALOG_H
#define MODULOCOLORDIALOG_H

#include "ui_modulocolordialog.h"

/**
 * @brief The ModuloColorDialog class is the one in charge of the QDialog to handle the "modulo color" filter.
 * @author Eddy IKHLEF
 */
class ModuloColorDialog : public QDialog, private Ui::ModuloColorDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param parent it's parent QWidget.
     * @author Eddy IKHLEF
     */
    explicit ModuloColorDialog(QWidget *parent = nullptr);
    ~ModuloColorDialog();
    /**
     * @brief getSelectedColor
     * @return the selected color as a QColor.
     * @author Eddy IKHLEF
     */
    QColor getSelectedColor();
    /**
     * @brief getSelectedValue
     * @return the selected integer value that correspond to the right side member of the modulo operand.
     * @author Eddy IKHLEF
     */
    int getSelectedValue();

protected slots:
    /**
     * @brief colorChanged slot method called when the user interact with the elements that contains
     *        color values for the color section in the ui.
     * @author Eddy IKHLEF
     */
    void colorChanged();
};

#endif // MODULOCOLORDIALOG_H
