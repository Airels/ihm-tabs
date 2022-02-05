#ifndef CONDITIONALCOLORDIALOG_H
#define CONDITIONALCOLORDIALOG_H

#include "ui_conditionalcolordialog.h"

/**
 * @brief The ConditionalColorDialog class is the one in charge of the QDialog to handle the "conditional color" filter.
 * @author Eddy IKHLEF
 */
class ConditionalColorDialog : public QDialog, private Ui::ConditionalColorDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param parent it's parent QWidget.
     * @author Eddy IKHLEF
     */
    explicit ConditionalColorDialog(QWidget *parent = nullptr);
    ~ConditionalColorDialog();
    QColor getSelectedColorMin();
    QColor getSelectedColorEqual();
    QColor getSelectedColorMax();
    double getSelectedValue();

protected slots:
    void colorChangedMin();
    void colorChangedEqual();
    void colorChangedMax();
};

#endif // CONDITIONALCOLORDIALOG_H
