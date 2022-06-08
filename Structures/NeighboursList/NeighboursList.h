#ifndef SDIZO_2_NEIGHBOURSLIST_H
#define SDIZO_2_NEIGHBOURSLIST_H

#include <cstddef>
#include <iostream>
#include "../Graph.h"

struct Edge
{
    Edge(const size_t &source_, const size_t &destination_, int cost_);

    int cost;
    size_t source;
    size_t destination;

    Edge* next = nullptr;
    Edge* previous = nullptr;
};

class NeighboursList : public Graph {

    Edge **edgeTable;

public:
    NeighboursList(const size_t& nodesNumber_, const size_t& edgesNumber_, const size_t* data);
    NeighboursList(const size_t& nodesNumber_, const size_t& edgesNumber_);
    ~NeighboursList();

    void addEdge(const size_t& source_, const size_t& destination_, const size_t& cost_);

    void displayGraph() override;

    size_t getNodesNumber() override;
    size_t getEdgesNumber() override;
    size_t getDensity() override;

    Edge** getEdgeTable();


};


#endif
