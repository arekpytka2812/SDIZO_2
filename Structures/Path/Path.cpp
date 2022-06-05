#include "Path.h"

Path::Path()
{

}

Path::~Path()
{
    delete[] this->nodes;
    delete[] this->costs;

    this->totalCost = 0;
    this->size = 0;
}

void Path::addFront(size_t node, size_t cost)
{
    if(this->size == 0)
    {
        totalCost = cost;

        this->nodes = new size_t;
        this->nodes[0] = node;

        this->costs = new size_t;
        this->costs[0] = cost;

        this->size++;

        return;
    }

    // adding certain cost to totalcost
    totalCost += cost;

    // creating tempTables to copy previous values
    auto tempNodes = new size_t[this->size + 1];
    auto tempCosts = new size_t[this->size + 1];

    // inserting new values
    tempNodes[0] = node;
    tempCosts[0] = cost;

    //copying old values
    for(int i = 1; i < this->size + 1; i++)
    {
        tempNodes[i] = nodes[i - 1];
        tempCosts[i] = costs[i - 1];
    }

    // realeasing old memory
    delete[] this->nodes;
    delete[] this->costs;

    // setting up pointers
    this->nodes = tempNodes;
    this->costs = tempCosts;

    //increasing size
    this->size++;
}

void Path::displayPath()
{
    if(this->size == 0)
    {
        std::cout << "There is no path!";
        return;
    }

    std::cout << "Path from: " << nodes[0] << " to " << nodes[this->size - 1] << std::endl;
    std::cout << "|" << nodes[0] << " : " << costs[0] << "|";

    for(int i = 1; i < this->size; i++)
    {
        std::cout << "  ->  |" << nodes[i] << " : " << costs[i] << "|";
    }

    std::cout << "\nTotal cost = " << totalCost << std::endl;
}