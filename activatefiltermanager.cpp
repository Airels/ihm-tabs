#include "activatefiltermanager.h"
#include <QCheckBox>
#include <QLayoutItem>
#include "fixedcolordialog.h"
#include "gradientcolordialog.h"

ActivateFilterManager::ActivateFilterManager(DataManager* dataManager, ViewManager* viewManager, QGroupBox* _activeFilter, QPushButton* _applyFilterBtn ) {
    this->dataManager = dataManager;
    this->viewManager = viewManager;
    this->_activeFilter = _activeFilter;
    this->_applyFilterBtn = _applyFilterBtn;
    this->_activeFilterLayout = new QVBoxLayout;
    this->_activeFilterLayout->setSpacing(0);
    this->_activeFilterLayout->setMargin(0);
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
            openGradientColor();
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
    this->_activeFilter->setLayout(_activeFilterLayout);
    FixedColorDialog* dialog = new FixedColorDialog();
    this->_activeFilterLayout->addWidget(dialog);
    updateSelection();
}

void ActivateFilterManager::openGradientColor() {
    this->_activeFilter->setLayout(_activeFilterLayout);
    GradientColorDialog* dialog = new GradientColorDialog();
    this->_activeFilterLayout->addWidget(dialog);
    updateSelection();
}


void ActivateFilterManager::applyFilter(QModelIndexList* model, int categoryIndex, int toolIndex) {
    qDebug() << "[USER ACTION] apply fixed color filter 2";
    QLayoutItem* child;
    switch(categoryIndex) {
    case 0:
        switch(toolIndex) {
        case 0: //Gradient Color

            if ((child = this->_activeFilterLayout->itemAt(0)) != nullptr) {
                GradientColorDialog* dialog = (GradientColorDialog*) child->widget();
                QColor colorMin = dialog->getSelectedColorMin();
                QColor colorMax = dialog->getSelectedColorMax();
                this->dataManager->apply_filter_min_max(*model, colorMin, colorMax);
            }
            break;
        case 1: //Fixed Color
            if ((child = this->_activeFilterLayout->itemAt(0)) != nullptr) {
                FixedColorDialog* dialog = (FixedColorDialog*) child->widget();
                QColor color = dialog->getSelectedColor();
                this->dataManager->apply_filter_fixed_color(*model, color);
            }
            break;
        }
        break;
    case 1:
        break;
    }
}
