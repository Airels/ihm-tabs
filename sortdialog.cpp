#include "sortdialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

int SortDialog::getSelectedValue() {
    return _valueBox->currentIndex();
}
