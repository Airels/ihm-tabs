#ifndef GENERATEDIALOG_H
#define GENERATEDIALOG_H

#include "ui_generatedialog.h"

#include <QDialogButtonBox>
#include <QDoubleSpinBox>

/**
 * @brief The GenerateDialog class
 * @author NICOLAI Guillaume (refractored by IKHLEF Eddy)
 */
class GenerateDialog : public QDialog, private Ui::GenerateDialog
{
    Q_OBJECT

public:
    /**
     * @brief GenerateDialog instanciates the dialog and constructs its widgets
     * @param parent its parent QWidget.
     * @author NICOLAI GUillaume
     */
    explicit GenerateDialog(QWidget *parent = nullptr);
    /**
     * @brief getNumberOfRows
     * @return the selected integer value that correspond to the number of rows to generate.
     * @author IKHLEF Eddy
     */
    int getNumberOfRows();
    /**
     * @brief getNumberOfCols
     * @return the selected integer value that correspond to the number of colums to generate.
     * @author IKHLEF Eddy
     */
    int getNumberOfCols();
    /**
     * @brief getMinValue
     * @return the selected double value that correspond to the minimum value to possibly generate.
     * @author IKHLEF Eddy
     */
    double getMinValue();
    /**
     * @brief getMaxValue
     * @return the selected double value that correspond to the maximum value to possibly generate.
     * @author IKHLEF Eddy
     */
    double getMaxValue();

private:
    /**
     * @brief nbOfRowsBox reference to the corresponding attribute of the ui.
     */
    QSpinBox *nbOfRowsBox;
    /**
     * @brief nbOfColsBox reference to the corresponding attribute of the ui.
     */
    QSpinBox *nbOfColsBox;
    /**
     * @brief minValueBox reference to the corresponding attribute of the ui.
     */
    QDoubleSpinBox *minValueBox;
    /**
     * @brief maxValueBox reference to the corresponding attribute of the ui.
     */
    QDoubleSpinBox *maxValueBox;
    /**
     * @brief buttonBox reference to the corresponding attribute of the ui.
     */
    QDialogButtonBox *buttonBox;
};

#endif // GENERATEDIALOG_H
