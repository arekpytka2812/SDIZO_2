#ifndef SDIZO_2_TESTS_H
#define SDIZO_2_TESTS_H


#include "../Timer/Timer.h"
#include "../FileManager/FileManager.h"
#include "../GraphGenerator/GraphGenerator.h"

#include "../../Structures/Graph.h"
#include "../../Structures/NeighboursList/NeighboursList.h"
#include "../../Structures/IncidenceMatrix/IncidenceMatrix.h"

#include "../../Algorithms/BellmanFord/BellmanFord.h"
#include "../../Algorithms/Dijsktra/Dijkstra.h"
#include "../../Algorithms/Kruskal/Kruskal.h"
#include "../../Algorithms/Prim/Prim.h"


class Tests {

    Timer *timer = nullptr;

    FileManager *fm = nullptr;

    NeighboursList *listForTests = nullptr;
    NeighboursList *returnList = nullptr;

    IncidenceMatrix *matrixForTests = nullptr;
    IncidenceMatrix *returnMatrix = nullptr;

    Path *returnPath = nullptr;

    GraphGenerator *gg = nullptr;

    constexpr static const int densities[4] = {25, 50, 75, 99};
    constexpr static const int nodesNumber[5] = {10, 20, 30, 40, 50};

    void MST();
    void shortestPath();

public:

    Tests();
    ~Tests();

    void allTests();

};


#endif
