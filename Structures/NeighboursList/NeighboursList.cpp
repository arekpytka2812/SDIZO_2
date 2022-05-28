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
            Edge *tempPointer = this->edgeTable[data[dataIndex]];

            while(tempPointer->next != nullptr)
            {
                tempPointer = tempPointer->next;
            }

            tempPointer->next = tempEdge;
            tempEdge->previous = tempPointer;
        }
        dataIndex += 3;

    }

    //density = static_cast<int>(((2 * this->edgesNumber) / (this->nodesNumber * (this->nodesNumber - 1))) * 100);
}

NeighboursList::NeighboursList(const size_t& nodesNumber_, const size_t& , const size_t&)
{

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