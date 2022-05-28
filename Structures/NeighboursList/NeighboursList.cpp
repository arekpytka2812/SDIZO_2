#include "NeighboursList.h"

Edge::Edge(const size_t &source_, const size_t &destination_, int cost_)
    : source(source_), destination(destination_), cost(cost_)
{

}

Edge::Edge()
{

}


NeighboursList::NeighboursList(const size_t& nodesNumber_, const size_t& edgesNumber_, const size_t* data)
    : nodesNumber(nodesNumber_), edgesNumber(edgesNumber_)
{
    this->edgeTable = new Edge * [this->nodesNumber];

    // initializing table with nullptrs
    for(int i = 0; i < this->nodesNumber; i++)
    {
        this->edgeTable[i] = nullptr;
    }

    // each edge is being inserted to the table
    for(int dataIndex = 0; dataIndex < this->edgesNumber * 3;)
    {
        auto tempEdge = new Edge(data[dataIndex], data[dataIndex + 1], data[dataIndex + 2]);

        if(this->edgeTable[data[dataIndex]] == nullptr)
            this->edgeTable[data[dataIndex]] = tempEdge;

        else
        {
            auto *tempPointer = this->edgeTable[data[dataIndex]];

            while(tempPointer->next != nullptr)
            {
                tempPointer = tempPointer->next;
            }

            tempPointer->next = tempEdge;
            tempEdge->previous = tempPointer;
        }
        dataIndex += 3;

    }

    this->density = ((2 * this->edgesNumber * 100) / (this->nodesNumber * (this->nodesNumber - 1)));

}

NeighboursList::NeighboursList(const size_t& nodesNumber_, const size_t& density_)
    : nodesNumber(nodesNumber_), density(density_)
{
    // calculating edge number from density and node number
    this->edgesNumber = (this->density ) * this->nodesNumber * (this->nodesNumber - 1) / 200;
    int currentEdgeNumber = this->edgesNumber;

    // initialinig table
    this->edgeTable = new Edge* [this->nodesNumber];

    for(int i = 0; i < this->nodesNumber; i++)
    {
        this->edgeTable[i] = nullptr;
    }

    // this loop makes connected graph by connecting node with next node
    for(int i = 0; i < this->nodesNumber && currentEdgeNumber != 0; i++)
    {
        Edge* tempEdge = nullptr;

        if(i == this->nodesNumber - 1)
            tempEdge = new Edge(i, 0, rand() % 10);

        else
            tempEdge = new Edge(i, i + 1, rand() % 10);


        if(edgeTable[i] == nullptr)
            edgeTable[i] = tempEdge;
        else
        {
            auto *tempPointer = this->edgeTable[i];

            while(tempPointer->next != nullptr)
            {
                tempPointer = tempPointer->next;
            }

            tempPointer->next = tempEdge;
            tempEdge->previous = tempPointer;
        }
        currentEdgeNumber--;
    }

    // if there are some edge to create this loop makes it
    while(currentEdgeNumber != 0)
    {
        bool exists = false;
        auto cost = rand() % 10;
        auto source = rand() % this->nodesNumber;
        auto destination = rand() % this->nodesNumber;

        // loop prevents from making edge to the same node
        while (destination == source)
        {
            destination = rand() % this->nodesNumber;
        }

        auto tempPointer = this->edgeTable[source];

        while(tempPointer != nullptr)
        {
            // this flag and if statement checks wheter edge with such parameters exists
            if(tempPointer->destination == destination)
            {
                exists = true;
                break;
            }

            // moving temp Pointer to the next edge
            if(tempPointer->next != nullptr)
                tempPointer = tempPointer->next;
            else
                break;
        }

        if(!exists)
        {
            // creating edge
            auto tempEdge = new Edge(source, destination, cost);
            tempPointer->next = tempEdge;
            tempEdge->previous = tempPointer;
            currentEdgeNumber--;
        }

    }

}

NeighboursList::~NeighboursList()
{
    for(int i = 0; i < this->nodesNumber; i++)
    {
        auto tempPointer = this->edgeTable[i];

        while(tempPointer->next != nullptr)
        {
            tempPointer = tempPointer->next;
            delete tempPointer->previous;
        }

        delete tempPointer;
    }

    delete[] this->edgeTable;

    this->nodesNumber = 0;
    this->edgesNumber = 0;
}

void NeighboursList::displayList()
{
    for (int i = 0; i < this->nodesNumber; i++)
    {
        auto tempPointer = this->edgeTable[i];

        std::cout << i << "    ";

        while(tempPointer != nullptr)
        {
            std::cout << "-> |" << tempPointer->destination << " : " << tempPointer->cost << "| ";
            tempPointer = tempPointer->next;
        }

        std::cout << "\n";
    }
}