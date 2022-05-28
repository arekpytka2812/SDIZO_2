#ifndef SDIZO_2_HEAP_H
#define SDIZO_2_HEAP_H

#include <stdexcept>
#include "NeighboursList/NeighboursList.h"


class Heap {

    Edge** table;
    int size;

    void heapify();

public:
    Heap();
    ~Heap();

    Edge& operator[](int);

    void push(Edge);
    void pop();
};


#endif
