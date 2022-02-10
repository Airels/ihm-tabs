#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include "ui_sortdialog.h"

/**
 * @brief The SortDialog class is the one in charge of the QDialog to handle the sort filter.
 * @author IKHLEF Eddy
 * @deprecated the sort is now implemented inside the tableView of the mainWindow and use a sorting function from dataManager.
 * @see datamanager.h
 * @see mainwindow.h
 */
class SortDialog : public QDialog, private Ui::SortDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Have to be linked with the followings parameters:
     * @param parent its parent QWidget.
     * @author IKHLEF Eddy
     */
    explicit SortDialog(QWidget *parent = nullptr);
    /**
     * @brief getSelectedValue
     * @return the selected integer value that correspond to the way to sort the selected column.
     * @author IKHLEF Eddy
     */
    int getSelectedValue();
};

#endif // SORTDIALOG_H
