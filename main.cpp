#include "main.h"


int main() {

    srand(time(nullptr));

    size_t tab[] = {
            0, 1, 4,
            0, 3, 8,
            1, 2, 8,
            1, 3, 11,
            2, 4, 2,
            2, 5, 4,
            3, 4, 7,
            3, 6, 1,
            4, 6, 6,
            5, 6, 2
    };

    auto gg = new GraphGenerator(40,80);


   // auto matrix = new IncidenceMatrix(6, 9, tab);
    auto list = new NeighboursList(7, 10, tab);

//    matrix->displayMatrix();
//
//    Prim::generateMST(matrix, 1);

    list->displayList();

    Prim::generateMST(list, 0)->displayList();

    std::cout << std::endl;

    Dijkstra::findShortestPath(list, 0);

    return 0;
}
