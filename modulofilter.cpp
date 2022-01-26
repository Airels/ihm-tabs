#include "modulofilter.h"
#include <tgmath.h>

ModuloFilter::ModuloFilter(int modulo,QColor color){
    this->moduloValue = modulo;
    this->color = color;

}

void ModuloFilter::apply(Cell * cell){
    double intPartOfValue = floor(cell->getvalue());

    if(intPartOfValue == cell->getvalue()){
        if((int)(intPartOfValue)%moduloValue == 0){
            cell->setColor(color);
        }
    }
}
