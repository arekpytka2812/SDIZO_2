#include "DijkstraAlgorithm.h"


NeighboursList* DijkstraAlgorithm::findShortestPath(NeighboursList *list, int source, int destination)
{
    auto nodesNumber = list->getNodesNumber();
    auto edgesNumber = list->getEdgesNumber();
    auto edgesTable = list->getEdgeTable();

    size_t* distances = new size_t [nodesNumber]{INT_MAX};
    int* previous = new int [nodesNumber]{-1};

    Heap *heap = new Heap();

    // inserting edge heap
    for(int i = 0; i < nodesNumber; i++)
    {
        auto tempEdge = edgesTable[i];

        while(tempEdge != nullptr)
        {
            heap->push(tempEdge);
            tempEdge = tempEdge->next;
        }

    }

    heap->printHeap();

    distances[source] = 0;
    int curentVertex = source;

//    while(heap->getSize())
//    {
//        auto minNode = heap->pop();
//
//        auto tempPointer = edgesTable[]
//
//        for(int i = 0; i < edgesTable[minNode->source]; i++)
//        {
//
//        }
//
//    }

    return nullptr;
}

IncidenceMatrix* DijkstraAlgorithm::findShortestPath(IncidenceMatrix *matrix, int source, int destination)
{

    return nullptr;
}