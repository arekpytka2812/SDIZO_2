#include "NeighboursList.h"

Edge::Edge(const size_t &source_, const size_t &destination_, int cost_)
    : source(source_), destination(destination_), cost(cost_)
{

}


NeighboursList::NeighboursList(const size_t& nodesNumber_, const size_t& edgesNumber_, const size_t* data)
{
    this->nodesNumber = nodesNumber_;
    this->edgesNumber = edgesNumber_;

    // initializing table with nullptrs
    this->edgeTable = new Edge * [this->nodesNumber]{nullptr};

    // each edge is being inserted to the table
    for(int dataIndex = 0; dataIndex < this->edgesNumber * 3;)
    {
        auto tempEdge = new Edge(data[dataIndex], data[dataIndex + 1], data[dataIndex + 2]);

        // checking if first pointer is empty
        if(this->edgeTable[data[dataIndex]] == nullptr)
            this->edgeTable[data[dataIndex]] = tempEdge;

        else
        {
            auto tempPointer = this->edgeTable[data[dataIndex]];

            // looping until last element of list
            while(tempPointer->next != nullptr)
            {
                tempPointer = tempPointer->next;
            }

            // setting up edge pointers
            tempPointer->next = tempEdge;
            tempEdge->previous = tempPointer;
        }
        dataIndex += 3;

    }

    // calculating density
    this->density = ((2 * this->edgesNumber * 100) / (this->nodesNumber * (this->nodesNumber - 1)));

}

NeighboursList::NeighboursList(const size_t& nodesNumber_, const size_t& edgesNumber_)
{
    this->nodesNumber = nodesNumber_;
    this->edgesNumber = edgesNumber_;

    // initializing table with nullptrs
    this->edgeTable = new Edge * [this->nodesNumber]{nullptr};
}

NeighboursList::~NeighboursList()
{
    for(int i = 0; i < this->nodesNumber; i++)
    {
        auto tempPointer = this->edgeTable[i];

        if(tempPointer == nullptr)
            continue;

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

void NeighboursList::addEdge(const size_t& source_, const size_t& destination_, const size_t& cost_)
{
    // creating temp edge with given data
    auto edge = new Edge(source_, destination_, cost_);

    // checking if first pointer is empty
    if(this->edgeTable[edge->source] == nullptr)
        edgeTable[edge->source] = edge;
    else
    {
        auto tempPointer = this->edgeTable[edge->source];

        // looping until last element of list
        while(tempPointer->next != nullptr)
        {
            tempPointer = tempPointer->next;
        }

        // setting up edge pointers
        tempPointer->next = edge;
        edge->previous = tempPointer;
    }
}

void NeighboursList::displayGraph()
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

size_t NeighboursList::getNodesNumber()
{
    return this->nodesNumber;
}

size_t NeighboursList::getEdgesNumber()
{
    return this->edgesNumber;
}

size_t NeighboursList::getDensity()
{
    return this->density;
}

Edge** NeighboursList::getEdgeTable()
{
    return this->edgeTable;
}