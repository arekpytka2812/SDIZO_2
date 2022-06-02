#include "GraphGenerator.h"

GraphGenerator::GraphGenerator(size_t nodesNumber_, size_t density_)
    :nodesNumber(nodesNumber_), density(density_)
{
    // calculating edges number
    this->edgesNumber = (this->density) * this->nodesNumber * (this->nodesNumber - 1) / 200;
    int currentEdgeNumber = this->edgesNumber;

    this->data = new size_t[this->edgesNumber * 3]{999};

    for(int i = 0; i < this->nodesNumber * 3; i += 3)
    {
        if(i == (this->nodesNumber * 3) - 3)
        {
            data[i] = i;
            data[i + 1] = 0;
            data[i + 2] = rand() % 100;
        }
        else
        {
            data[i] = i;
            data[i + 1] = i + 1;
            data[i + 2] = rand() % 100;
        }

        this->size += 3;

        currentEdgeNumber--;
    }

    while(currentEdgeNumber != 0)
    {
        bool exists = false;
        int source = rand() % this->nodesNumber;
        int destination = rand() % this->nodesNumber;
        int cost = rand() % 100;

        while(source == destination)
        {
            destination = rand() % this->nodesNumber;
        }

        for(int i = 0; data[i] != 999; i += 3)
        {
            if(data[i] == source && data[i + 1] == destination)
            {
                exists = true;
                break;
            }
        }

        if(!exists)
        {
            data[this->size] = source;
            data[this->size + 1] = destination;
            data[this->size + 2] = cost;

            this->size += 3;
            currentEdgeNumber--;
        }
    }
}

GraphGenerator::~GraphGenerator()
{
    delete[] this->data;

    this->nodesNumber = 0;
    this->edgesNumber = 0;
    this->density = 0;

}