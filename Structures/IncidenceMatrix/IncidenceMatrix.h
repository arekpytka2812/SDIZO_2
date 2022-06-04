#ifndef SDIZO_2_INCIDENCEMATRIX_H
#define SDIZO_2_INCIDENCEMATRIX_H

#include <cstdlib>
#include <iostream>
#include <iomanip>

class IncidenceMatrix {

    size_t nodesNumber;
    size_t edgesNumber;
    size_t density;

    size_t usedEdges = 0;

    int **matrix;
    int *edgesValues;

public:

    IncidenceMatrix(const size_t & nodeNumber_, const size_t &edgeNumber_, const size_t *data);
    IncidenceMatrix(const size_t & nodeNumber_, const size_t &edgeNumber_);
    ~IncidenceMatrix();

    void addEdge(const size_t &source, const size_t &destination, const size_t &cost);

    void displayMatrix();

    size_t getNodesNumber()
    {
        return this->nodesNumber;
    }

    size_t getEdgesNumber()
    {
        return this->edgesNumber;
    }

    int** getMatrix()
    {
        return this->matrix;
    }

    int* getEdgesValues()
    {
        return this->edgesValues;
    }
};


#endif
