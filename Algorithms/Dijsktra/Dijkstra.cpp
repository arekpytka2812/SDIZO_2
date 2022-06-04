#include "Dijkstra.h"

IncidenceMatrix* Dijkstra::findShortestPath(IncidenceMatrix *matrix, int source)
{

    return nullptr;
}

NeighboursList* Dijkstra::findShortestPath(NeighboursList *list, int source)
{
    auto nodesNumber = list->getNodesNumber();
    auto edgesNumber = list->getEdgesNumber();
    auto edgesTable = list->getEdgeTable();

    auto heap = new Heap();
    auto returnList = new NeighboursList(nodesNumber, edgesNumber);

    auto distances = new size_t [nodesNumber];
    auto previous = new int [nodesNumber];
    auto visitedNodes = new bool [nodesNumber];
    auto nodesToRelax = new bool [nodesNumber];

    for(int i = 0; i < nodesNumber; i++)
    {
        distances[i] = INT_MAX;
        previous[i] = -1;
        visitedNodes[i] = false;
        nodesToRelax[i] = true;
    }

    // inserting edge heap

    auto tempEdge = edgesTable[source];

    while(tempEdge != nullptr)
    {
        heap->push(tempEdge);
        tempEdge = tempEdge->next;
    }

    distances[source] = 0;
    visitedNodes[source] = true;
    nodesToRelax[source] = false;
    int currentNode = source;

    Edge *minNode = nullptr;

    while(isEmpty(visitedNodes, nodesNumber))
    {
        if(heap->getSize() != 0)
        {
            minNode = heap->pop();

            visitedNodes[minNode->destination] = true;

            if(distances[minNode->destination] > distances[minNode->source] + minNode->cost)
            {
                distances[minNode->destination] = distances[minNode->source] + minNode->cost;
                previous[minNode->destination] = minNode->source;
            }

            continue;
        }

        nodesToRelax[currentNode] = false;
        visitedNodes[minNode->destination] = true;

        currentNode = getMin(distances, visitedNodes, nodesToRelax, nodesNumber);

        tempEdge = edgesTable[currentNode];
        while(tempEdge != nullptr)
        {
            heap->push(tempEdge);
            tempEdge = tempEdge->next;
        }

    }

    for(int i = 0; i < nodesNumber; i++)
        std::cout << distances[i] << "    ";

    std::cout << "\n";

    for(int i = 0; i < nodesNumber; i++)
        std::cout << previous[i] << "    ";

    minNode = nullptr;
    tempEdge = nullptr;

    delete heap;
    delete[] previous;
    delete[] distances;
    delete[] nodesToRelax;



    return nullptr;
}

bool Dijkstra::isEmpty(bool *table, size_t size)
{
    for(int i = 0; i < size; i++)
        if(!table[i])
            return true;
    return false;
}

int Dijkstra::getMin(size_t *table, bool* visited, bool *toRelax, size_t size)
{
    int min = INT_MAX;
    int index =  0;

    for(int i = 0; i < size; i++)
    {
        if(table[i] < min && visited[i] && toRelax[i])
        {
            index = i;
            min = table[i];
        }
    }

    return index;
}