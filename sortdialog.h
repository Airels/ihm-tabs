#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include "ui_sortdialog.h"

/**
 * @brief The SortDialog class is the one in charge of the QDialog to handle the sort filter.
 * @author Eddy IKHLEF
 */
class SortDialog : public QDialog, private Ui::SortDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param parent it's parent QWidget.
     * @author Eddy IKHLEF
     */
    explicit SortDialog(QWidget *parent = nullptr);
    /**
     * @brief getSelectedValue
     * @return the selected integer value that correspond to the way to sort the selected column.
     * @author Eddy IKHLEF
     */
    int getSelectedValue();
};

#endif // SORTDIALOG_H
