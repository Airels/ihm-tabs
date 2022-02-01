#ifndef MODULOCOLORDIALOG_H
#define MODULOCOLORDIALOG_H

#include "ui_modulocolordialog.h"

class ModuloColorDialog : public QDialog, private Ui::ModuloColorDialog
{
    Q_OBJECT

public:
    explicit ModuloColorDialog(QWidget *parent = nullptr);
    ~ModuloColorDialog();
    QColor getSelectedColor();
    int getSelectedValue();

protected slots:
    void colorChanged();
};

#endif // MODULOCOLORDIALOG_H
