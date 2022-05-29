#include "main.h"

int main() {

    srand(time(nullptr));

    size_t tab[] = {
            0, 1, 2,
            0, 2, 4,
            1, 2, 2,
            1, 3, 4,
            1, 4, 2,
            2, 4, 3,
            3, 4, 3,
            3, 5, 2,
            4, 5, 2
    };

    auto matrix = new IncidenceMatrix(6, 9, tab);

    matrix->displayMatrix();

    return 0;
}
