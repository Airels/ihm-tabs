#ifndef FIXEDCOLORDIALOG_H
#define FIXEDCOLORDIALOG_H

#include "ui_fixedcolordialog.h"

class FixedColorDialog : public QDialog, private Ui::FixedColorDialog
{
    Q_OBJECT

public:
    FixedColorDialog(QWidget *parent = nullptr);
    ~FixedColorDialog();
    QColor getSelectedColor();

protected slots:
    void colorChanged();
};

#endif // FIXEDCOLORDIALOG_H
