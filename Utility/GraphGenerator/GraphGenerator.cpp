#include <cmath>
#include "GraphGenerator.h"

// TODO check wheter graph will be connected

GraphGenerator::GraphGenerator(size_t nodesNumber_, size_t density_)
    :nodesNumber(nodesNumber_), density(density_)
{
    // calculating edges number
    this->edgesNumber = (this->density) * this->nodesNumber * (this->nodesNumber - 1) / 200;
    int currentEdgeNumber = this->edgesNumber;

    // initializing data table
    this->data = new size_t[this->edgesNumber * 3];

    for(int i = 0; i < this->edgesNumber * 3; i++)
    {
        data[i] = INT_MAX;
    }

    // making sure
    for(int i = 0; i < this->nodesNumber; i++)
    {
        if(i == this->nodesNumber - 1)
        {
            data[i * 3] = i;
            data[i * 3 + 1] = 0;
            data[i * 3 + 2] = rand() % 100;
        }
        else
        {
            data[i * 3] = i;
            data[i * 3 + 1] = i + 1;
            data[i * 3 + 2] = rand() % 100;
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

        for(int i = 0; data[i] != INT_MAX; i += 3)
        {
            if(data[i] == source && data[i + 1] == destination || data[i] == destination && data[i + 1] == source)
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