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
    QColor getSelectedColor();

protected slots:
    void colorChanged();
};

#endif // FIXEDCOLORDIALOG_H
