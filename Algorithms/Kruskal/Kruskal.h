#ifndef SDIZO_2_KRUSKAL_H
#define SDIZO_2_KRUSKAL_H


#include "../../Structures/NeighboursList/NeighboursList.h"
#include "../../Structures/IncidenceMatrix/IncidenceMatrix.h"
#include "../../Structures/EdgeHeap/Heap.h"

class Kruskal {

    static bool isEmpty(bool* table, size_t size);

public:

    // TODO create special type for returns

    static IncidenceMatrix* generateMST(IncidenceMatrix* incidenceMatrix);

    static NeighboursList* generateMST(NeighboursList* list);
};


#endif
