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

 //   auto matrix = new IncidenceMatrix(6, 80);

//    matrix->displayMatrix();

    auto gg = new GraphGenerator(6,80);

    auto list = new NeighboursList(gg->getNodesNumber(), gg->getEdgesNumber(), gg->getData());

    list->displayList();

    auto matrix = new IncidenceMatrix(gg->getNodesNumber(), gg->getEdgesNumber(), gg->getData());

    matrix->displayMatrix();




    //DijkstraAlgorithm::findShortestPath(list, 2, 5);

    return 0;
}
