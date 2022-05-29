#ifndef SDIZO_2_HEAP_H
#define SDIZO_2_HEAP_H

#include <stdexcept>
#include "../NeighboursList/NeighboursList.h"


class Heap {

    Edge** table;
    int size;

    void heapify(int i);

public:
    Heap();
    ~Heap();

    Edge* operator[](int);

    void push(Edge* edge);
    Edge* pop();

    void printHeap();

    void buildHeap();

    int getSize()
    {
        return this->size;
    }
};


#endif
