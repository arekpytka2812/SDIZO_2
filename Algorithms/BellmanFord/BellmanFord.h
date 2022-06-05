#ifndef SDIZO_2_BELLMANFORD_H
#define SDIZO_2_BELLMANFORD_H


#include "../../Structures/IncidenceMatrix/IncidenceMatrix.h"
#include "../../Structures/NeighboursList/NeighboursList.h"
#include "../../Structures/EdgeHeap/Heap.h"

class BellmanFord {

    static int getMin(bool* visited, bool* toRelax, size_t size);

public:

    // TODO add "to" parameter and change the return type

    static IncidenceMatrix* findShortestPath(IncidenceMatrix *incidenceMatrix, int from);

    static NeighboursList* findShortestPath(NeighboursList *list, int from);

};


#endif
