#include "datamanager.h"
#include "fixedcolorfilter.h"

DataManager::DataManager()
{

}

void DataManager::apply_filter_fixed_color(int row, int col, QColor color) {
    FixedColorFilter filter = FixedColorFilter(color);

    int row_max = 0, col_max = 0; // TODO

    if (row == -1 && col == -1) {
        for (int x = 0; x < row_max; x++) {
            for (int y = 0; y < col_max; y++) {
                filter.apply((Cell *) cells.item(x, y));
            }
        }
    } else if (row == -1) {
        for (int x = 0; x < row_max; x++) {
            filter.apply((Cell *) cells.item(x, col));
        }
    } else if (col == -1) {
        for (int y = 0; y < col_max; y++) {
            filter.apply((Cell *) cells.item(row, y));
        }
    } else {
        filter.apply((Cell *) cells.item(row, col));
    }
}

// row = 1; column = -1;
/*
void DataManager::apply_filter_min_max(int row, int column, QColor gradientMin, QColor gradientMax) {
    Filter filter = Filter(fjjqzd);

    for (int column = 0; column < max; column++) {
        Cell cell = cells.item(row, column);
        filter.apply(cell);
    }
}
*/
