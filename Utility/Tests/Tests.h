#ifndef SDIZO_2_TESTS_H
#define SDIZO_2_TESTS_H


#include "../Timer/Timer.h"
#include "../../Structures/Graph.h"
#include "../FileManager/FileManager.h"

class Tests {

    Timer *timer = nullptr;
    FileManager *fm = nullptr;

    Graph* graph = nullptr;

    constexpr static const int densities[4] = {25, 50, 75, 99};
    constexpr static const int nodesNumber[5] = {10, 15, 20, 25, 30};

    int currentNodesNumber;
    int currentDensity;

public:

    Tests();
    ~Tests();

    void MST();
    void shortestPath();

    void allTests();

};


#endif
