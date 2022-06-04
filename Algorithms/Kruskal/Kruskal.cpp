#include "Kruskal.h"

IncidenceMatrix* Kruskal::generateMST(IncidenceMatrix* matrix)
{

    return nullptr;
}

NeighboursList* Kruskal::generateMST(NeighboursList* list)
{
    auto edgesNumber = list->getEdgesNumber();
    auto nodesNumber = list->getNodesNumber();
    auto edgesTable = list->getEdgeTable();

    auto heap = new Heap();
    auto listToReturn = new NeighboursList(nodesNumber, edgesNumber);

    auto visitedNodes = new bool[nodesNumber]{false};
    int totalCost = 0;

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



    while(isEmpty(visitedNodes, nodesNumber))
    {
        auto minNode = heap->pop();

        if(visitedNodes[minNode->source] && visitedNodes[minNode->destination])
            continue;

        if(!visitedNodes[minNode->source] && !visitedNodes[minNode->destination])
        {
            visitedNodes[minNode->source] = true;
            visitedNodes[minNode->destination] = true;

            tempEdge = edgesTable[minNode->source];
            while(tempEdge != nullptr)
            {
                heap->push(tempEdge);
                tempEdge = tempEdge->next;
            }

            tempEdge = edgesTable[minNode->destination];
            while(tempEdge != nullptr)
            {
                heap->push(tempEdge);
                tempEdge = tempEdge->next;
            }

            tempEdge = new Edge(minNode->source, minNode->destination, minNode->cost);

            listToReturn->addEdge(tempEdge);

            totalCost += minNode->cost;

            continue;
        }

        if(!visitedNodes[minNode->source])
        {
            visitedNodes[minNode->source] = true;

            tempEdge = edgesTable[minNode->source];
            while(tempEdge != nullptr)
            {
                heap->push(tempEdge);
                tempEdge = tempEdge->next;
            }

            tempEdge = new Edge(minNode->source, minNode->destination, minNode->cost);

            listToReturn->addEdge(tempEdge);

            totalCost += minNode->cost;
        }

        if(!visitedNodes[minNode->destination])
        {
            visitedNodes[minNode->destination] = true;

            tempEdge = edgesTable[minNode->destination];
            while(tempEdge != nullptr)
            {
                heap->push(tempEdge);
                tempEdge = tempEdge->next;
            }

            tempEdge = new Edge(minNode->source, minNode->destination, minNode->cost);

            listToReturn->addEdge(tempEdge);

            totalCost += minNode->cost;
        }
    }

    std::cout << std::endl;

    listToReturn->displayList();

    std::cout << std::endl << "totalCost  = " << totalCost << std::endl;

    return nullptr;
}



bool Kruskal::isEmpty(bool *table, size_t size)
{
    for(int i = 0; i < size; i++)
        if(!table[i])
            return true;
    return false;

}