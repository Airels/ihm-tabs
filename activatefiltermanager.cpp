#include "activatefiltermanager.h"
#include <QCheckBox>
#include <QLayoutItem>
#include <QLabel>
#include <QSpinBox>
#include <QGridLayout>

ActivateFilterManager::ActivateFilterManager(DataManager* dataManager, ViewManager* viewManager, QGroupBox* _activeFilter, QPushButton* _applyFilterBtn ) {
    this->dataManager = dataManager;
    this->viewManager = viewManager;
    this->_activeFilter = _activeFilter;
    this->_applyFilterBtn = _applyFilterBtn;
    this->_activeFilterLayout = new QVBoxLayout;
}

ActivateFilterManager::~ActivateFilterManager() {
    delete this->name;
}

void ActivateFilterManager::handle(int categoryIndex, int toolIndex) {
    if(this->name == nullptr) return;
    clearSelection();
    switch(categoryIndex) {
    case 0:
        switch(toolIndex) {
        case 0:
            break;
        case 1:
            openFixedColor();
            break;
        }
        break;
    case 1:
        break;
    }
}

void ActivateFilterManager::clearSelection() {
    this->_applyFilterBtn->setEnabled(false);
    this->_activeFilter->setTitle("");
    disconnect(this->_applyFilterBtn, SIGNAL(clicked()));
    QLayoutItem* child;
    while ((child = this->_activeFilterLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}

void ActivateFilterManager::updateSelection() {
    this->_activeFilter->setTitle(*this->name);
    this->_applyFilterBtn->setEnabled(true);
    this->name = nullptr;
}

void ActivateFilterManager::setFilterName(QString name) {
    this->name = &name;
}

void ActivateFilterManager::openFixedColor() {
    //_activeFilterLayout = new GridLayout();
    this->_activeFilter->setLayout(_activeFilterLayout);
    QLabel* label = new QLabel("Color Value");
    QSpinBox* rSpin = new QSpinBox(); rSpin->setMaximum(255); rSpin->setMinimum(0);

    this->_activeFilterLayout->addWidget(label);
    this->_activeFilterLayout->addWidget(rSpin);
    updateSelection();
}


void ActivateFilterManager::applyFilter(QModelIndexList* model, int categoryIndex, int toolIndex) {
    qDebug() << "[USER ACTION] apply fixed color filter 2";
    switch(categoryIndex) {
    case 0:
        switch(toolIndex) {
        case 0: //Gradient Color
            break;
        case 1: //Fixed Color
            QColor* color = new QColor(255,0,0);
            this->dataManager->apply_filter_fixed_color(*model, *color);
            delete color;
            break;
        }
        break;
    case 1:
        break;
    }
}
