#ifndef SDIZO_2_DIJKSTRAALGORITHM_H
#define SDIZO_2_DIJKSTRAALGORITHM_H


#include "../../Structures/NeighboursList/NeighboursList.h"
#include "../../Structures/IncidenceMatrix/IncidenceMatrix.h"

class DijkstraAlgorithm{

public:
    static NeighboursList* findShortestPath(NeighboursList *list);

    static IncidenceMatrix* findShortestPath(IncidenceMatrix *matrix);
};


#endif
