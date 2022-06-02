#ifndef SDIZO_2_GRAPHGENERATOR_H
#define SDIZO_2_GRAPHGENERATOR_H


#include <cstdlib>

class GraphGenerator {

    size_t nodesNumber;
    size_t edgesNumber;
    size_t density;

    size_t * data = nullptr;

    size_t size = 0;

public:

    GraphGenerator(size_t nodesNumber_, size_t density);
    ~GraphGenerator();

    size_t getNodesNumber()
    {
        return this->nodesNumber;
    }

    size_t getEdgesNumber()
    {
        return this->edgesNumber;
    }

    size_t getDensity()
    {
        return this->density;
    }

    size_t* getData()
    {
        return this->data;
    }
};


#endif
