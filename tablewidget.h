#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include "cell.h"

namespace Ui {
class TableWidget;
}

class TableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidget(QWidget *parent = nullptr);
    ~TableWidget();

private:
    Ui::TableWidget *ui;
};

#endif // TABLEWIDGET_H
