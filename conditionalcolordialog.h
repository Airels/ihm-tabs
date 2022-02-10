#ifndef CONDITIONALCOLORDIALOG_H
#define CONDITIONALCOLORDIALOG_H

#include "ui_conditionalcolordialog.h"

/**
 * @brief The ConditionalColorDialog class is the one in charge of the QDialog to handle the "conditional color" filter.
 * @author IKHLEF Eddy
 */
class ConditionalColorDialog : public QDialog, private Ui::ConditionalColorDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param parent its parent QWidget.
     * @author IKHLEF Eddy
     */
    explicit ConditionalColorDialog(QWidget *parent = nullptr);
    ~ConditionalColorDialog();
    /**
     * @brief getSelectedColorMin
     * @return the selected "minimum color" as a QColor.
     * @author IKHLEF Eddy
     */
    QColor getSelectedColorMin();
    /**
     * @brief getSelectedColorEqual
     * @return the selected "equal color" as a QColor.
     * @author IKHLEF Eddy
     */
    QColor getSelectedColorEqual();
    /**
     * @brief getSelectedColorMax
     * @return the selected "maximum color" as a QColor.
     * @author IKHLEF Eddy
     */
    QColor getSelectedColorMax();
    /**
     * @brief getSelectedValue
     * @return the selected "conditional value" that correspond to the right side operand of the <, =, > contidions.
     * @author IKHLEF Eddy
     */
    double getSelectedValue();

protected slots:
    /**
     * @brief colorChangedMin slot method called when the user interact with the elements that contains
     *        color values for the "minimum color" section in the ui.
     * @author IKHLEF Eddy
     */
    void colorChangedMin();
    /**
     * @brief colorChangedEqual slot method called when the user interact with the elements that contains
     *        color values for the "equal color" section in the ui.
     * @author IKHLEF Eddy
     */
    void colorChangedEqual();
    /**
     * @brief colorChangedMax slot method called when the user interact with the elements that contains
     *        color values for the "maximum color" section in the ui.
     * @author IKHLEF Eddy
     */
    void colorChangedMax();
};

#endif // CONDITIONALCOLORDIALOG_H
