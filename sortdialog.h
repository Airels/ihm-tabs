#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include "ui_sortdialog.h"

class SortDialog : public QDialog, private Ui::SortDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = nullptr);
    /**
     * @brief getSelectedValue
     * @return the selected integer value that correspond to the way to sort the selected column.
     * @author Eddy IKHLEF
     */
    int getSelectedValue();
};

#endif // SORTDIALOG_H
