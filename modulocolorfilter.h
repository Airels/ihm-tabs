#ifndef MODULOCOLORFILTER_H
#define MODULOCOLORFILTER_H

#include "ui_modulocolorfilter.h"

class moduloColorFilter : public QDialog, private Ui::moduloColorFilter
{
    Q_OBJECT

public:
    explicit moduloColorFilter(QWidget *parent = nullptr);
};

#endif // MODULOCOLORFILTER_H
