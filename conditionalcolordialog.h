#ifndef CONDITIONALCOLORDIALOG_H
#define CONDITIONALCOLORDIALOG_H

#include "ui_conditionalcolordialog.h"

class ConditionalColorDialog : public QDialog, private Ui::ConditionalColorDialog
{
    Q_OBJECT

public:
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
