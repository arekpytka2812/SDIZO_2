#ifndef SDIZO_2_DIJKSTRAALGORITHM_H
#define SDIZO_2_DIJKSTRAALGORITHM_H

#include "../../Structures/EdgeHeap/Heap.h"

#include "../../Structures/NeighboursList/NeighboursList.h"
#include "../../Structures/IncidenceMatrix/IncidenceMatrix.h"

class DijkstraAlgorithm{

public:
    static NeighboursList* findShortestPath(NeighboursList *list, int source, int destination);

    static IncidenceMatrix* findShortestPath(IncidenceMatrix *matrix, int source, int destination);
};


#endif
