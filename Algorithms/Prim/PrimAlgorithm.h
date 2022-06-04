#ifndef SDIZO_2_PRIMALGORITHM_H
#define SDIZO_2_PRIMALGORITHM_H

#include "../../Structures/IncidenceMatrix/IncidenceMatrix.h"
#include "../../Structures/NeighboursList/NeighboursList.h"
#include "../../Structures/EdgeHeap/Heap.h"

class Prim{

    static bool isEmpty(bool* table, size_t size);

public:
    static IncidenceMatrix* generateMST(IncidenceMatrix* incidenceMatrix, int from);

    static NeighboursList* generateMST(NeighboursList* list, int from);
};



#endif
