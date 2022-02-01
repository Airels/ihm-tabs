#ifndef GRADIENTCOLORDIALOG_H
#define GRADIENTCOLORDIALOG_H

#include "ui_gradientcolordialog.h"

class GradientColorDialog : public QDialog, private Ui::GradientColorDialog
{
    Q_OBJECT

public:
    GradientColorDialog(QWidget *parent = nullptr);
    ~GradientColorDialog();
    QColor getSelectedColorMin();
    QColor getSelectedColorMax();

protected slots:
    void colorChangedMin();
    void colorChangedMax();
};

#endif // GRADIENTCOLORDIALOG_H
