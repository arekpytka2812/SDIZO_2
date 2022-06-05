#ifndef SDIZO_2_BELLMANFORD_H
#define SDIZO_2_BELLMANFORD_H


#include "../../Structures/IncidenceMatrix/IncidenceMatrix.h"
#include "../../Structures/NeighboursList/NeighboursList.h"
#include "../../Structures/EdgeHeap/Heap.h"
#include "../../Structures/Path/Path.h"

class BellmanFord {

    static int getMin(bool* visited, bool* toRelax, size_t size);

public:

    static Path* findShortestPath(IncidenceMatrix *incidenceMatrix, int from, int to);

    static Path* findShortestPath(NeighboursList *list, int from, int to);

};


#endif
