#include "main.h"

// TODO 1) add writting to file
// TODO 2) create tests
// TODO 3) create menu


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

    auto gg = new GraphGenerator(15, 80);

    auto matrix = new IncidenceMatrix(6, 9, tab);
    auto list = new NeighboursList(6, 9, tab);

//    matrix->displayMatrix();

    list->displayList();

    Dijkstra::findShortestPath(list, 5, 3)->displayPath();

 //   Dijkstra::findShortestPath(matrix, 0, 5)->displayPath();
  //  path->displayPath();
//
//    Kruskal::generateMST(matrix);
//
//    std::cout << std::endl;
//
//    Kruskal::generateMST(list)->displayList();
//    std::cout << std::endl;

    return 0;
}
