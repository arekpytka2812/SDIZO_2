#include "main.h"


int main() {



    srand(time(nullptr));

    size_t tab[] = {
            0, 1, 1,
            0, 2, 8,
            1, 2, 2,
            1, 3, 8,
            1, 4, 4,
            2, 4, 3,
            3, 4, 5,
            3, 5, 8,
            4, 5, 3
    };

    auto gg = new GraphGenerator(6,80);

    auto matrix = new IncidenceMatrix(6, 9, tab);
    auto list = new NeighboursList(6, 9, tab);

    matrix->displayMatrix();

    Prim::generateMST(matrix, 1);

    list->displayList();

    Prim::generateMST(list, 1)->displayList();

    return 0;
}
