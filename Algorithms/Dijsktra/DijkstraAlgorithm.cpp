#include "DijkstraAlgorithm.h"


NeighboursList* DijkstraAlgorithm::findShortestPath(NeighboursList *list, int source, int destination)
{
    auto nodesNumber = list->getNodesNumber();
    auto edgesNumber = list->getEdgesNumber();
    auto edgesTable = list->getEdgeTable();

    size_t* distances = new size_t [nodesNumber];

    Heap *heap = new Heap();

    // inserting distance values and
    for(int i = 0, j = 0; i < edgesNumber && j < nodesNumber; j++, i++)
    {
        distances[j] = INT_MAX;

        auto tempEdge = edgesTable[i];

        while(tempEdge != nullptr)
        {
            heap->push(tempEdge);
            //std::cout << i << " " << tempEdge->cost << "\n";

            tempEdge = tempEdge->next;
        }

    }

    distances[source] = 0;

    while(heap->getSize())
    {
        auto minNode = heap->pop();

        heap->printHeap();
        std::cout << "\n";

    }

    return nullptr;
}

IncidenceMatrix* DijkstraAlgorithm::findShortestPath(IncidenceMatrix *matrix, int source, int destination)
{

    return nullptr;
}