#ifndef ACTIVATEFILTERMANAGER_H
#define ACTIVATEFILTERMANAGER_H
#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>

class ActivateFilterManager : public QObject
{
public:
    ActivateFilterManager(QGroupBox* _activeFilter, QPushButton* _applyFilterBtn);
    ~ActivateFilterManager();
    QWidget* handle(int categoryIndex, int toolIndex);
    void setFilterName(QString name);
private:
    void clearSelection();
    void updateSelection(QWidget*& filterMenu);
    QGroupBox* _activeFilter;
    QPushButton* _applyFilterBtn;
    QVBoxLayout* _activeFilterLayout;
    QString* name = nullptr;
};

#endif // ACTIVATEFILTERMANAGER_H
