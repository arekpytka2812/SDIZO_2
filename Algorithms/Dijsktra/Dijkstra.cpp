#include "Dijkstra.h"

Path* Dijkstra::findShortestPath(IncidenceMatrix *incidenceMatrix, int from, int to)
{
    auto nodesNumber = incidenceMatrix->getNodesNumber();
    auto edgesNumber = incidenceMatrix->getEdgesNumber();
    auto matrix = incidenceMatrix->getMatrix();
    auto edgeValues =  incidenceMatrix->getEdgesValues();

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

    for(int i = 0; i < edgesNumber; i++)
    {
        size_t source, destination;

        if(matrix[from][i] == -1)
        {
            source = from;

            for(int j = 0; j < nodesNumber; j++)
                if(matrix[j][i] == 1)
                {
                    destination = j;
                    break;
                }


            heap->push(new Edge(source, destination, edgeValues[i]));
        }
    }


    distances[from] = 0;
    visitedNodes[from] = true;
    nodesToRelax[from] = false;
    int currentNode = from;

    Edge *minEdge = nullptr;

    while(isEmpty(visitedNodes, nodesNumber))
    {
        if(heap->getSize() != 0)
        {
            minEdge = heap->pop();

            if(distances[minEdge->destination] > distances[minEdge->source] + minEdge->cost)
            {
                distances[minEdge->destination] = distances[minEdge->source] + minEdge->cost;
                previous[minEdge->destination] = minEdge->source;
            }

            continue;
        }

        nodesToRelax[currentNode] = false;
        visitedNodes[currentNode] = true;

        currentNode = getMin(distances, visitedNodes, nodesToRelax, nodesNumber);

        if(currentNode == -1)
            break;

        for(int i = 0; i < edgesNumber; i++)
        {
            size_t source, destination;

            if(matrix[currentNode][i] == -1)
            {
                source = currentNode;

                for(int j = 0; j < nodesNumber; j++)
                {
                    if(matrix[j][i] == 1)
                    {
                        destination = j;
                        break;
                    }
                }

                heap->push(new Edge(source, destination, edgeValues[i]));
            }
        }

    }

    // variables for creating Path
    auto resultPath = new Path();
    auto currentIndex = to;
    auto tempPrevious = previous[currentIndex];

    do
    {
        if(currentIndex == from)
        {
            resultPath->addFront(currentIndex, 0);
            break;
        }

        if(distances[currentIndex] == INT_MAX)
            break;

        resultPath->addFront(currentIndex, distances[currentIndex] - distances[tempPrevious]);

        currentIndex = tempPrevious;
        tempPrevious = previous[currentIndex];

    }while(currentIndex != -1);

    minEdge = nullptr;

    delete heap;
    delete[] previous;
    delete[] distances;
    delete[] nodesToRelax;

    return resultPath;
}

Path* Dijkstra::findShortestPath(NeighboursList *list, int from, int to)
{
    // initializing necessary variables
    auto nodesNumber = list->getNodesNumber();
    auto edgesNumber = list->getEdgesNumber();
    auto edgesTable = list->getEdgeTable();

    auto heap = new Heap();
    auto returnList = new NeighboursList(nodesNumber, edgesNumber);

    auto distances = new size_t [nodesNumber];
    auto previous = new int [nodesNumber];
    auto visitedNodes = new bool [nodesNumber];
    auto nodesToRelax = new bool [nodesNumber];

    // inserting default values to the arrays
    for(int i = 0; i < nodesNumber; i++)
    {
        distances[i] = INT_MAX;
        previous[i] = -1;
        visitedNodes[i] = false;
        nodesToRelax[i] = true;
    }

    // inserting edge heap
    auto tempEdge = edgesTable[from];

    while(tempEdge != nullptr)
    {
        heap->push(tempEdge);
        tempEdge = tempEdge->next;
    }

    // setting source variables to default
    distances[from] = 0;
    visitedNodes[from] = true;
    nodesToRelax[from] = false;
    int currentNode = from;

    Edge *minNode = nullptr;

    // main algorithm
    while(isEmpty(visitedNodes, nodesNumber))
    {
        if(heap->getSize() != 0)
        {
            // poping min current node edge
            minNode = heap->pop();

            // dijsktra condition
            if(distances[minNode->destination] > distances[minNode->source] + minNode->cost)
            {
                distances[minNode->destination] = distances[minNode->source] + minNode->cost;
                previous[minNode->destination] = minNode->source;
            }

            continue;
        }

        // setting current node flags
        nodesToRelax[currentNode] = false;
        visitedNodes[currentNode] = true;

        // getting new node to dheck
        currentNode = getMin(distances, visitedNodes, nodesToRelax, nodesNumber);

        // if there is no right node, the algorithm will end
        if(currentNode == -1)
            break;

        // pushing into heap edges of current node
        tempEdge = edgesTable[currentNode];
        while(tempEdge != nullptr)
        {
            heap->push(tempEdge);
            tempEdge = tempEdge->next;
        }

    }

    // variables for creating Path
    auto resultPath = new Path();
    auto currentIndex = to;
    auto tempPrevious = previous[currentIndex];

    do
    {
        if(currentIndex == from)
        {
            resultPath->addFront(currentIndex, 0);
            break;
        }

        if(distances[currentIndex] == INT_MAX)
            break;

        resultPath->addFront(currentIndex, distances[currentIndex] - distances[tempPrevious]);

        currentIndex = tempPrevious;
        tempPrevious = previous[currentIndex];

    }while(currentIndex != -1);

    // clearing and realeasing memory
    minNode = nullptr;
    tempEdge = nullptr;

    delete heap;
    delete[] previous;
    delete[] distances;
    delete[] nodesToRelax;

    return resultPath;
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
    int index =  -1;

    for(int i = 0; i < size; i++)
    {
        if(table[i] < min && !visited[i] && toRelax[i])
        {
            index = i;
            min = table[i];
        }
    }

    return index;
}