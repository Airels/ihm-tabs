#ifndef CELL_H
#define CELL_H
#include <QString>
#include <QColor>
#include <QApplication>
#include <QStandardItem>

/**
 * @brief The Cell class helps to work with the selected data (cell's value and cell's color).
 *        Elements of this class will be used by DataManager and filters classes.
 *        By doing so, we can easily retrieve the data of a cell and update them, by doing so,
 *        correspondings fields herited from the QStandardItem will automatically be updated.
 *
 * @authors Yohan VIZCAINO, Eddy IKHLEF
 */
class Cell: public QStandardItem
{

public:
    /**
     * @brief Constructor of the class. Allows to instanciate a cell with a specific value and color.
     * @param value the given double value of the cell.
     * @param color the given QColor of the cell.
     * @author Eddy IKHLEF
     */
    Cell(double value, QColor color);
    /**
     * @brief Constructor of the class. Allows to instanciate a cell with a specific value only.
     *        The instanciated cell will have a base color defined by the implementation (white for example).
     * @param value the given double value of the cell.
     * @author Yohan VIZCAINO
     */
    Cell(double value);
    ~Cell();

    /**
     * @brief getvalue
     * @return the value of the cell.
     * @author Eddy IKHLEF
     */
    double getvalue();
    /**
     * @brief setValue sets the value of the cell : sets the "value" member, the Text, and the custom Data
     * @param value the new value of the cell to be set.
     * @authors Eddy IKHLEF, BRICOUT Titouan
     */
    void setValue(double value);
    /**
     * @brief getColor
     * @return the QColor of the cell.
     * @author Eddy IKHLEF
     */
    QColor getColor();
    /**
     * @brief setColor
     * @param color the new QColor of the cell to be set.
     * @author Eddy IKHLEF
     */
    void setColor(QColor color);
    bool isUpdatable();

    /**
     * @brief setUpdatable
     * @param updatable boolean value to set the cell as an updatable cell (true) or not (false).
     *        an updatable cell can have its value updated. a non updatable cell cannot have its value updated.
     * @author Yohan VIZCAINO
     */
    //void setUpdatable(bool updatable);

private:
    double value;
    QColor color;
    const bool updatable = false;
};

#endif // CELL_H
