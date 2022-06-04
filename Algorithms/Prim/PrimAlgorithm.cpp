#include "PrimAlgorithm.h"

// TODO create special type for returns

IncidenceMatrix* Prim::generateMST(IncidenceMatrix* incidenceMatrix, int from)
{
    // initializing local variables
    auto edgesNumber = incidenceMatrix->getEdgesNumber();
    auto nodesNumber = incidenceMatrix->getNodesNumber();
    auto matrix = incidenceMatrix->getMatrix();
    auto edgeValues = incidenceMatrix->getEdgesValues();

    int totalCost = 0;

    auto heap = new Heap();
    auto resultMatrix = new IncidenceMatrix(nodesNumber, edgesNumber);

    auto visitedNodes = new bool[nodesNumber]{false};
    visitedNodes[from] = true;

    // inserting edge heap
    for(int i = 0; i < edgesNumber; i++)
    {
        size_t source, destination;

        if(matrix[from][i] != 0)
        {
            for(int j = 0; j < nodesNumber; j++)
            {
                if(matrix[j][i] == -1)
                    source = j;

                if(matrix[j][i] == 1)
                    destination = j;
            }

            heap->push(new Edge(source, destination, edgeValues[i]));
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
            totalCost += minEdge->cost;
            visitedNodes[minEdge->destination] = true;

            resultMatrix->addEdge(minEdge->source, minEdge->destination, minEdge->cost);

            // adding new edges to heap
            for(int i = 0; i < edgesNumber; i++)
            {
                size_t source, destination;

                if(matrix[minEdge->source][i] != 0 || matrix[minEdge->destination != 0])
                {
                    for(int j = 0; j < nodesNumber; j++)
                    {
                        if(matrix[j][i] == -1)
                            source = j;

                        if(matrix[j][i] == 1)
                            destination = j;
                    }

                    heap->push(new Edge(source, destination, edgeValues[i]));
                }
            }
        }

        if(!visitedNodes[minEdge->source])
        {
            totalCost += minEdge->cost;
            visitedNodes[minEdge->source] = true;

            resultMatrix->addEdge(minEdge->source, minEdge->destination, minEdge->cost);

            // adding new edges to heap
            for(int i = 0; i < edgesNumber; i++)
            {
                size_t source, destination;

                if(matrix[minEdge->source][i] != 0 || matrix[minEdge->destination])
                {
                    for(int j = 0; j < nodesNumber; j++)
                    {
                        if(matrix[j][i] == -1)
                            source = j;

                        if(matrix[j][i] == 1)
                            destination = j;
                    }

                    heap->push(new Edge(source, destination, edgeValues[i]));
                }
            }
        }
    }

    resultMatrix->displayMatrix();

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