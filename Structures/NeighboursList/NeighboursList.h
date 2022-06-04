#ifndef SDIZO_2_NEIGHBOURSLIST_H
#define SDIZO_2_NEIGHBOURSLIST_H

#include <cstddef>
#include <iostream>

struct Edge
{
    Edge(const size_t &source_, const size_t &destination_, int cost_);

    Edge();

    int cost;
    size_t source;
    size_t destination;

    Edge* next = nullptr;
    Edge* previous = nullptr;
};

class NeighboursList {

    size_t nodesNumber;
    size_t edgesNumber;
    size_t density;

    Edge **edgeTable;

public:
    NeighboursList(const size_t& nodesNumber_, const size_t& edgesNumber_, const size_t* data);
    NeighboursList(const size_t& nodesNumber_, const size_t& edgesNumber_);
    ~NeighboursList();

    void addEdge(Edge * edge);

    void displayList();

    Edge** getEdgeTable()
    {
        return this->edgeTable;
    }

    size_t getNodesNumber()
    {
        return this->nodesNumber;
    }

    size_t getEdgesNumber()
    {
        return this->edgesNumber;
    }

};


#endif
