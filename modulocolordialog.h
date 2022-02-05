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
    QColor getSelectedColor();
    int getSelectedValue();

protected slots:
    void colorChanged();
};

#endif // MODULOCOLORDIALOG_H
