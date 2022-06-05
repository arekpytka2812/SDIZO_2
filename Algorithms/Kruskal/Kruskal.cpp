#include "Kruskal.h"

IncidenceMatrix* Kruskal::generateMST(IncidenceMatrix* incidenceMatrix)
{
    auto edgesNumber = incidenceMatrix->getEdgesNumber();
    auto nodesNumber = incidenceMatrix->getNodesNumber();
    auto matrix = incidenceMatrix->getMatrix();
    auto edgeValues = incidenceMatrix->getEdgesValues();

    auto heap = new Heap();
    auto resultMatrix = new IncidenceMatrix(nodesNumber, edgesNumber);

    int totalCost = 0;
    int connectingEdges = 0;

    auto setsID = new size_t[nodesNumber];

    for(int i = 0; i < nodesNumber; i++)
    {
        setsID[i] = i;
    }

    // inserting edge heap
    for(int i = 0; i < edgesNumber; i++)
    {
        size_t source, destination;

        for(int j = 0; j < nodesNumber; j++)
        {
            if(matrix[j][i] == -1)
                source = j;

            if(matrix[j][i] == 1)
                destination = j;
        }

        heap->push(new Edge(source, destination, edgeValues[i]));
    }

    while(heap->getSize())
    {
        if(connectingEdges == nodesNumber - 1)
            break;

        auto minEdge = heap->pop();

        if(setsID[minEdge->source] != setsID[minEdge->destination])
        {
            resultMatrix->addEdge(minEdge->source, minEdge->destination, minEdge->cost);

            auto oldID = setsID[minEdge->source];
            auto newID = setsID[minEdge->destination];

            for(int i = 0; i < nodesNumber; i++)
            {
                if(setsID[i] == oldID)
                    setsID[i] = newID;
            }

            totalCost += minEdge->cost;
            connectingEdges++;
        }
    }

    return resultMatrix;
}

NeighboursList* Kruskal::generateMST(NeighboursList* list)
{
    auto edgesNumber = list->getEdgesNumber();
    auto nodesNumber = list->getNodesNumber();
    auto edgesTable = list->getEdgeTable();

    auto heap = new Heap();
    auto listToReturn = new NeighboursList(nodesNumber, edgesNumber);

    int totalCost = 0;
    int connectingEdges = 0;

    auto setsID = new size_t[nodesNumber];

    for(int i = 0; i < nodesNumber; i++)
    {
        setsID[i] = i;
    }

    Edge* tempEdge = nullptr;

    for(int i = 0; i < nodesNumber; i++)
    {
        tempEdge = edgesTable[i];

        while(tempEdge != nullptr)
        {
            heap->push(tempEdge);
            tempEdge = tempEdge->next;
        }
    }


    while(heap->getSize())
    {
        auto minEdge = heap->pop();

        if(connectingEdges == nodesNumber - 1)
            break;

        if(setsID[minEdge->source] != setsID[minEdge->destination])
        {
            listToReturn->addEdge(minEdge->source, minEdge->destination, minEdge->cost);

            auto oldID = setsID[minEdge->source];
            auto newID = setsID[minEdge->destination];

            for(int i = 0; i < nodesNumber; i++)
            {
                if(setsID[i] == oldID)
                    setsID[i] = newID;
            }

            totalCost += minEdge->cost;
            connectingEdges++;
        }
    }

    tempEdge = nullptr;
    delete heap;
    delete[] setsID;

    return listToReturn;
}



bool Kruskal::isEmpty(bool *table, size_t size)
{
    for(int i = 0; i < size; i++)
        if(!table[i])
            return true;
    return false;

}