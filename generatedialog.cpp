#include "generatedialog.h"
#include <QDoubleSpinBox>
#include <qformlayout.h>
#include <qlabel.h>
#include <float.h>
#include <qdialogbuttonbox.h>
#include <QIcon>

GenerateDialog::GenerateDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setupUi(this);
    this->setWindowIcon(QIcon(":/icon.png"));
    QFormLayout* form = new QFormLayout();
    verticalLayout->addLayout(form);
    form->addRow(new QLabel("Please give following values:"));
    // Value1
    QString rowStr = QString("Number of rows: ");
    nbOfRowsBox = new QSpinBox(this);
    nbOfRowsBox->setMaximum(INT_MAX);
    nbOfRowsBox->setMinimum(1);
    nbOfRowsBox->setAlignment(Qt::AlignRight);
    form->addRow(rowStr, nbOfRowsBox);
    // Value2
    QString columnStr = QString("Number of columns: ");
    nbOfColsBox = new QSpinBox(this);
    nbOfColsBox->setMaximum(INT_MAX);
    nbOfColsBox->setMinimum(1);
    nbOfColsBox->setAlignment(Qt::AlignRight);
    form->addRow(columnStr, nbOfColsBox);

    // Value 3
    QString maxValueStr = QString("Maximal value (not required): ");
    maxValueBox = new QDoubleSpinBox(this);
    maxValueBox->setMaximum(DBL_MAX);
    maxValueBox->setMinimum(-DBL_MAX);
    maxValueBox->setAlignment(Qt::AlignRight);
    form->addRow(maxValueStr, maxValueBox);
    // Value 4
    QString minValueStr = QString("Minimal value (not required): ");
    minValueBox = new QDoubleSpinBox(this);
    minValueBox->setMaximum(DBL_MAX);
    minValueBox->setMinimum(-DBL_MAX);
    minValueBox->setAlignment(Qt::AlignRight);
    form->addRow(minValueStr, minValueBox);

    // Add Cancel and OK button
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,Qt::Horizontal, this);
    form->addRow(buttonBox);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

int GenerateDialog::getNumberOfRows() {
    return nbOfRowsBox->value();
}

int GenerateDialog::getNumberOfCols() {
    return nbOfColsBox->value();
}

double GenerateDialog::getMinValue() {
    return (int) minValueBox->value();
}

double GenerateDialog::getMaxValue() {
    return (int) maxValueBox->value();
}
