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


    auto matrix = new IncidenceMatrix(7, 10, tab);
    auto list = new NeighboursList(7, 10, tab);

    list->displayList();
    BellmanFord::findShortestPath(matrix, 0);

    std::cout << std::endl;

    BellmanFord::findShortestPath(list, 0);



    return 0;
}
