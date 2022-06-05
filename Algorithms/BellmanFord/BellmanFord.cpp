#include "BellmanFord.h"


IncidenceMatrix* BellmanFord::findShortestPath(IncidenceMatrix *incidenceMatrix, int from)
{
    auto nodesNumber = incidenceMatrix->getNodesNumber();
    auto edgesNumber = incidenceMatrix->getEdgesNumber();
    auto matrix = incidenceMatrix->getMatrix();
    auto edgeValues = incidenceMatrix->getEdgesValues();

    auto returnMatrix = new IncidenceMatrix(nodesNumber, edgesNumber);

    auto distances = new size_t [nodesNumber];
    auto previous = new int [nodesNumber];

    bool hasChanged = false;

    for(int i = 0; i < nodesNumber; i++)
    {
        distances[i] = INT_MAX;
        previous[i] = -1;
    }

    distances[from] = 0;
    Edge *tempEdge = nullptr;

    for(int i = 0; i < nodesNumber - 1; i++)
    {

        for(int source = 0; source < nodesNumber; source++)
        {
            if(distances[source] == INT_MAX)
                continue;

            for(int edge = 0; edge < edgesNumber; edge++)
            {
                if (matrix[source][edge] != -1)
                    continue;

                for(int destination = 0; destination < edgesNumber; destination++)
                {
                    if(matrix[destination][edge] != 1)
                        continue;

                    if (distances[destination] > distances[source] + edgeValues[edge])
                    {
                        distances[destination] = distances[source] + edgeValues[edge];
                        previous[destination] = source;

                        hasChanged = true;
                    }

                    break;
                }

            }
        }

        if(!hasChanged)
            break;
    }

    for(int i = 0; i < nodesNumber; i++)
        std::cout << distances[i] << "    ";

    std::cout << "\n";

    for(int i = 0; i < nodesNumber; i++)
        std::cout << previous[i] << "    ";

    return nullptr;
}

NeighboursList* BellmanFord::findShortestPath(NeighboursList *list, int from)
{
    auto nodesNumber = list->getNodesNumber();
    auto edgesNumber = list->getEdgesNumber();
    auto edgesTable = list->getEdgeTable();

    auto returnList = new NeighboursList(nodesNumber, edgesNumber);

    auto distances = new size_t [nodesNumber];
    auto previous = new int [nodesNumber];

    bool hasChanged = false;

    for(int i = 0; i < nodesNumber; i++)
    {
        distances[i] = INT_MAX;
        previous[i] = -1;
    }

    distances[from] = 0;
    for(int i = 0; i < nodesNumber - 1; i++)
    {
        for(int j = 0; j < nodesNumber; j++)
        {
            if(distances[j] == INT_MAX)
                continue;

            auto tempEdge = edgesTable[j];

            while (tempEdge != nullptr)
            {
                if (distances[tempEdge->destination] > distances[tempEdge->source] + tempEdge->cost) {
                    distances[tempEdge->destination] = distances[tempEdge->source] + tempEdge->cost;
                    previous[tempEdge->destination] = tempEdge->source;

                    hasChanged = true;
                }

                if (tempEdge->next != nullptr)
                    tempEdge = tempEdge->next;
                else
                    break;
            }

            if (!hasChanged)
                break;
        }
    }

    for(int i = 0; i < nodesNumber; i++)
        std::cout << distances[i] << "    ";

    std::cout << "\n";

    for(int i = 0; i < nodesNumber; i++)
        std::cout << previous[i] << "    ";

    return nullptr;
}

int BellmanFord::getMin(bool* visited, bool* toRelax, size_t size)
{
    for(int i = 0; i < size; i++)
        if(visited[i] && toRelax[i])
            return i;
    return -1;
}