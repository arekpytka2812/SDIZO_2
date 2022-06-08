#include "main.h"

/*
    TODO 1) create tests
    TODO 2) create menu
    TODO 3) change printing
    TODO 4) add comments
 */

int main() {

    int chuj;

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

    auto gg = new GraphGenerator(10, 65);

    IncidenceMatrix* matrix = nullptr;
    NeighboursList* list = nullptr;

    matrix = new IncidenceMatrix(6, 9, tab);
    list = new NeighboursList(6, 9, tab);

    Graph* graphs[2] = {matrix, list};

    matrix->displayGraph();
    list->displayGraph();

    graphs[0]->displayGraph();
    graphs[1]->displayGraph();

    delete matrix;
    delete list;

//    BellmanFord::findShortestPath(list, 0, 5)->displayPath();
//
//    std::cout << std::endl;
//
//    BellmanFord::findShortestPath(matrix, 0, 5)->displayPath();
//
//    std::cout << std::endl;
//
//    Dijkstra::findShortestPath(list, 0, 5)->displayPath();
//
//    std::cout << std::endl;
//
//    Dijkstra::findShortestPath(matrix, 0, 5)->displayPath();
//
//    Dijkstra::findShortestPath(matrix, 0, 5)->displayPath();
//
//    Kruskal::generateMST(matrix);
//
//    std::cout << std::endl;
//
//    Kruskal::generateMST(list)->displayList();
//    std::cout << std::endl;

    return 0;
}
