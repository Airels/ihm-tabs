#include "activatefiltermanager.h"
#include <QCheckBox>
#include <QLayoutItem>

ActivateFilterManager::ActivateFilterManager(QGroupBox* _activeFilter, QPushButton* _applyFilterBtn ) {
    this->_activeFilter = _activeFilter;
    this->_activeFilterLayout = new QVBoxLayout;
    this->_applyFilterBtn = _applyFilterBtn;
    this->_activeFilter->setLayout(_activeFilterLayout);
}

ActivateFilterManager::~ActivateFilterManager() {
    delete this->name;
    delete this->_activeFilterLayout;
}

QWidget* ActivateFilterManager::handle(int categoryIndex, int toolIndex) {
    if(this->name == nullptr) return nullptr;
    clearSelection();
    switch(categoryIndex) {
    case 0:
        switch(toolIndex) {
        case 0:
            break;
        case 1:
            break;
        default:
            return nullptr;
        }
        break;
    case 1:
        break;
    default:
        return nullptr;
    }
    QWidget* checkbox = new QCheckBox("test");
    updateSelection(checkbox);
    return checkbox;
}

void ActivateFilterManager::clearSelection() {
    this->_applyFilterBtn->setEnabled(false);
    this->_activeFilter->setTitle("");
    disconnect(this->_applyFilterBtn, SIGNAL(clicked()));
    QLayoutItem* filterMenuItem;
    while ((filterMenuItem = this->_activeFilterLayout->takeAt(0)) != 0) {
        if (!filterMenuItem->widget()) continue;
        filterMenuItem->widget()->setParent(NULL);
        delete filterMenuItem;
    }
}

void ActivateFilterManager::updateSelection(QWidget*& filterMenu) {
    if(filterMenu == nullptr) return;
    this->_activeFilter->setTitle(*this->name);
    this->_activeFilterLayout->addWidget(filterMenu);
    //connect(ui->_applyFilterBtn, SIGNAL(clicked()), this, SLOT(applyFilter()));
    this->_applyFilterBtn->setEnabled(true);
    this->name = nullptr;
    qDebug() << "iciiiiii";
    QWidget* filterMenu2 = new QCheckBox("ogogo");
    this->_activeFilterLayout->addWidget(filterMenu2);
}

void ActivateFilterManager::setFilterName(QString name) {
    this->name = &name;
}
