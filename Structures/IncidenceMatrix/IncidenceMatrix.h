#ifndef SDIZO_2_INCIDENCEMATRIX_H
#define SDIZO_2_INCIDENCEMATRIX_H

#include <cstdlib>
#include <iostream>
#include <iomanip>

class IncidenceMatrix {

    size_t nodeNumber;
    size_t edgeNumber;

    int **matrix;
    int *edgesValues;

public:

    IncidenceMatrix(const size_t&, const size_t&, const size_t*);
    ~IncidenceMatrix();

    void displayMatrix();

    size_t getNodeNumber()
    {
        return this->nodeNumber;
    }

    size_t getEdgeNumber()
    {
        return this->edgeNumber;
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
