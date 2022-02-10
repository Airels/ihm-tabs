#include "sortdialog.h"
#include <QDebug>

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

int SortDialog::getSelectedValue() {
    if(_buttonAscending->isChecked()) return 0;
    else if(_buttonDescending->isChecked()) return 1;
    return -1;
}
