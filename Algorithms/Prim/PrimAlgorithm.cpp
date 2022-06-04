#include "PrimAlgorithm.h"


IncidenceMatrix* Prim::generateMST(IncidenceMatrix* matrix, int from)
{


    return nullptr;
}

NeighboursList* Prim::generateMST(NeighboursList* list, int from)
{
    // initializing local variables
    auto edgesNumber = list->getEdgesNumber();
    auto nodesNumber = list->getNodesNumber();
    auto edgesTable = list->getEdgeTable();

    auto heap = new Heap();

    auto visitedNodes = new bool[nodesNumber]{false};
    visitedNodes[from] = true;

    int totalCost = 0;

    // creating result list
    auto listToReturn = new NeighboursList(nodesNumber, edgesNumber);

    Edge* tempPointer = nullptr;

    // inserting heap with start edges
    for(int i = 0; i < nodesNumber; i++)
    {
        tempPointer = edgesTable[i];

        while(tempPointer != nullptr)
        {
            if(tempPointer->source == from || tempPointer->destination == from)
            {
                heap->push(tempPointer);
            }
            tempPointer = tempPointer->next;
        }
    }

    // main algorithm
    while(isEmpty(visitedNodes, nodesNumber))
    {
        // popping edge with min cost
        auto minEdge = heap->pop();

        // checking if node has been already visited
        // if hasnt, adding it to result list
        if(!visitedNodes[minEdge->destination])
        {
            auto tempEdge = new Edge(minEdge->source, minEdge->destination, minEdge->cost);

            totalCost += minEdge->cost;
            visitedNodes[minEdge->destination] = true;

            listToReturn->addEdge(tempEdge);

            // adding new edges to heap
            for(int i = 0; i < nodesNumber; i++)
            {
                tempPointer = edgesTable[i];

                while(tempPointer != nullptr)
                {
                    if(tempPointer->source == minEdge->destination || tempPointer->destination == minEdge->destination)
                    {
                        heap->push(tempPointer);
                    }
                    tempPointer = tempPointer->next;
                }
            }
        }

        if(!visitedNodes[minEdge->source])
        {
            auto tempEdge = new Edge(minEdge->destination, minEdge->source, minEdge->cost);

            totalCost += minEdge->cost;
            visitedNodes[minEdge->source] = true;

            listToReturn->addEdge(tempEdge);

            // adding new edges to heap
            for(int i = 0; i < nodesNumber; i++)
            {
                tempPointer = edgesTable[i];

                while(tempPointer != nullptr)
                {
                    if(tempPointer->source == minEdge->source || tempPointer->destination == minEdge->source)
                    {
                        heap->push(tempPointer);
                    }
                    tempPointer = tempPointer->next;
                }
            }
        }
    }

    // realeasing memory
    delete tempPointer;
    delete[] visitedNodes;
    delete heap;

    return listToReturn;
}

bool Prim::isEmpty(bool *table, size_t size)
{
    for(int i = 0; i < size; i++)
        if(!table[i])
            return true;
    return false;
}