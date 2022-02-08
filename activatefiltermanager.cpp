#include "activatefiltermanager.h"
#include <QCheckBox>
#include <QLayoutItem>
#include <QDebug>
#include "fixedcolordialog.h"
#include "gradientcolordialog.h"

ActivateFilterManager::ActivateFilterManager(DataManager* dataManager, QGroupBox* _activeFilter, QPushButton* _applyFilterBtn ) {
    this->dataManager = dataManager;
    this->_activeFilter = _activeFilter;
    this->_applyFilterBtn = _applyFilterBtn;
    this->gradientColorDialog =  new GradientColorDialog();
    this->fixedColorDialog = new FixedColorDialog();
    this->conditionalColorDialog = new ConditionalColorDialog();
    this->moduloColorDialog = new ModuloColorDialog();
    this->sortDialog = new SortDialog();
    createLayout();
}

ActivateFilterManager::~ActivateFilterManager() {
    delete this->name;
    delete this->gradientColorDialog;
    delete this->fixedColorDialog;
    delete this->conditionalColorDialog;
    delete this->moduloColorDialog;
    delete this->sortDialog;
}

void ActivateFilterManager::createLayout() {
    this->_activeFilterLayout = new QVBoxLayout;
    this->_activeFilterLayout->setSpacing(0);
    this->_activeFilterLayout->setMargin(0);
}

void ActivateFilterManager::handle(int categoryIndex, int toolIndex) {
    if(this->name == nullptr) return;
    clearSelection();
    switch(categoryIndex) {
    case 0:
        switch(toolIndex) {
        case 0: //Gradient
            openGradientColor();
            break;
        case 1: //Fixed
            openFixedColor();
            break;
        case 2: //Conditional
            openConditionalColor();
            break;
        case 3: //Modulo
            openModuloColor();
            break;
        default:
            break;
        }
        break;
    case 1:
        switch(toolIndex) {
        case 0: //Sort
            openSort();
            break;
        default: break;
        }
        break;
    default:
        break;
    }
}

void ActivateFilterManager::clearSelection() {
    this->_applyFilterBtn->setEnabled(false);
    this->_activeFilter->setTitle("");
    disconnect(this->_applyFilterBtn, SIGNAL(clicked()));
    QLayoutItem* child;
    while ((child = this->_activeFilterLayout->takeAt(0)) != nullptr) {
        child->widget()->setParent(nullptr);
    }
    this->_activeFilter->setLayout(_activeFilterLayout);
}

void ActivateFilterManager::updateSelection() {
    this->_activeFilter->setTitle(*this->name);
    this->_applyFilterBtn->setEnabled(true);
    this->name = nullptr;
}

void ActivateFilterManager::setFilterName(QString name) {
    qDebug() << name;
    qDebug() << &name;
    qDebug() << this->name;
    this->name = &name;
}

void ActivateFilterManager::openFixedColor() {
    this->_activeFilterLayout->addWidget(this->fixedColorDialog);
    updateSelection();
}

void ActivateFilterManager::openGradientColor() {
    this->_activeFilterLayout->addWidget(this->gradientColorDialog);
    updateSelection();
}

void ActivateFilterManager::openConditionalColor() {
    this->_activeFilterLayout->addWidget(this->conditionalColorDialog);
    updateSelection();
}

void ActivateFilterManager::openModuloColor() {
    this->_activeFilterLayout->addWidget(this->moduloColorDialog);
    updateSelection();
}

void ActivateFilterManager::openSort() {
    this->_activeFilterLayout->addWidget(this->sortDialog);
    updateSelection();
}


void ActivateFilterManager::applyFilter(QModelIndexList* model, int categoryIndex, int toolIndex) {
    qDebug() << "[USER ACTION] apply fixed color filter 2";
    switch(categoryIndex) {
    case 0:
        switch(toolIndex) {
        case 0: //Gradient Color
            if (this->gradientColorDialog != nullptr) {
                QColor colorMin = this->gradientColorDialog->getSelectedColorMin();
                QColor colorMax = this->gradientColorDialog->getSelectedColorMax();
                this->dataManager->apply_filter_min_max(*model, colorMin, colorMax);
            }
            break;
        case 1: //Fixed Color
            if (this->fixedColorDialog != nullptr) {
                QColor color = this->fixedColorDialog->getSelectedColor();
                this->dataManager->apply_filter_fixed_color(*model, color);
            }
            break;
        case 2: //Condition
            if (this->conditionalColorDialog != nullptr) {
                QColor colorMin = this->conditionalColorDialog->getSelectedColorMin();
                QColor colorEqual = this->conditionalColorDialog->getSelectedColorEqual();
                QColor colorMax = this->conditionalColorDialog->getSelectedColorMax();
                int value = this->conditionalColorDialog->getSelectedValue();
                this->dataManager->apply_filter_simplified_condition(*model, value, colorMin, colorEqual, colorMax);
            }
            break;
        case 3: //Modulo
            if (this->moduloColorDialog != nullptr) {
                QColor color = this->moduloColorDialog->getSelectedColor();
                int value = this->moduloColorDialog->getSelectedValue();
                this->dataManager->apply_filter_modulo(*model, value, color);
            }
            break;
        default:
            break;
        }
        break;
    case 1:
        switch(toolIndex) {
        case 0: //Sort
            if (this->sortDialog != nullptr) {
                int value = this->sortDialog->getSelectedValue();
                if(value == 0) {
                    //todo find a way to fetch col value or else add a column selection to the filter
                    this->dataManager->getCells()->sort(0, Qt::AscendingOrder);
                } else if(value == 1){
                    this->dataManager->getCells()->sort(0, Qt::DescendingOrder);
                }
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
