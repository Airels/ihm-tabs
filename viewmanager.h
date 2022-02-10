#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QApplication>
#include <QTableView>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QImage>

/**
 * @brief The ViewManager class handle operations to and from the various views, currently the TableView and the Image
 * @author BRICOUT Titouan
 */
class ViewManager : public QObject
{
Q_OBJECT
public:
    /**
     * @brief ViewManager constructor. Does not link the tableView, to an existing model.
     * Does not create the image.
     * @param tableView the Table View to be handled by the View Manager
     * @author BRICOUT Titouan
     */
    ViewManager(QTableView *tableView);

    /**
     * @brief ViewManager constructor. Links the tableView to the model and creates the image.
     * @param tableView the Table View to be handled by the View Manager
     * @param model the model from which the views get and show the data
     * @author BRICOUT Titouan
     */
    ViewManager(QTableView *tableView, QStandardItemModel *model);

    /**
     * @brief ViewManager constructor. Links the tableView to the model and creates the image.
     * @param tableView the Table View to be handled by the View Manager
     * @param model the model from which the views get and show the data
     * @param selectionModel the Selection Model to be used by the Table View, allowing it to share a selection Model
     * @author BRICOUT Titouan
     */
    ViewManager(QTableView *tableView, QStandardItemModel *model, QItemSelectionModel *selectionModel);
    ~ViewManager();
    /**
     * @brief getTableView
     * @return a pointer to the Table View
     */
    QTableView *getTableView();
    /**
     * @brief getImage
     * @return a pointer to the Image
     */
    QImage *getImage();

    /**
     * @brief updateImage builds the image by setting every pixel's color according to the model data
     * @note : bad complexity in theory, but enough for our application
     * @author BRICOUT Titouan
     */
    void updateImage();

signals:
    /**
     * @brief selectionUpdated signal sent whenever the user selects items
     * @param selectedIndexes the IndexList representing the selected items
     * @note : currently, simply forwards the View's selectionChanged signal
     * @author BRICOUT Titouan
     */
    void selectionUpdated(const QModelIndexList &selectedIndexes);

    /**
     * @brief sortRequested signal sent when the user double-clicks on a column header
     * @param column the column clicked
     * @param order the order to use for the sort (ascending or descending)
     * @author BRICOUT Titouan
     */
    void sortRequested(int column, Qt::SortOrder order);

protected slots:
    /**
     * @brief requestSort emits the sortRequested signal with the right sort order when the user double-clicks on a column header
     * Is triggered by the sectionDoubleClicked signal from the table View's horizontal header
     * @param column the column clicked
     * @author BRICOUT Titouan
     */
    void requestSort(int column);

private:

    /**
     * @brief setConnexions connects the useful signals from the views
     * @author BRICOUT Titouan
     */
    void setConnexions();

    /**
     * @brief myModel the model used by the views
     */
    QStandardItemModel *myModel;

    /**
     * @brief myTableView the table View used to display the model's data
     */
    QTableView *myTableView;

    /**
     * @brief myImage the image showing every cell from the model as a colored pixel
     */
    QImage *myImage;
};

#endif // VIEWMANAGER_H
