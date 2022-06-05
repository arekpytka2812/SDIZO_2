#ifndef SDIZO_2_DIJKSTRA_H
#define SDIZO_2_DIJKSTRA_H

#include "../../Structures/EdgeHeap/Heap.h"

#include "../../Structures/NeighboursList/NeighboursList.h"
#include "../../Structures/IncidenceMatrix/IncidenceMatrix.h"

class Dijkstra{

    static bool isEmpty(bool *table, size_t size);
    static int getMin(size_t *table, bool* visited, bool *toRelax, size_t size);

public:

    // TODO add "to" parameter and change the return type

    static IncidenceMatrix* findShortestPath(IncidenceMatrix *incidenceMatrix, int from);

    static NeighboursList* findShortestPath(NeighboursList *list, int from);
};


#endif
