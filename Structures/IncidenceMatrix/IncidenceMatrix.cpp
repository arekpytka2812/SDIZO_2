#include "IncidenceMatrix.h"

IncidenceMatrix::IncidenceMatrix(const size_t & nodeNumber_, const size_t &edgeNumber_, const size_t *data)
{
    this->nodesNumber = nodeNumber_;
    this->edgesNumber = edgeNumber_;

    // initializing matrix with zeros

    this->matrix = new int *[nodesNumber];

    for (int i = 0; i < nodesNumber; i++) {
        matrix[i] = new int[edgesNumber];

        for (int j = 0; j < edgesNumber; j++)
            matrix[i][j] = 0;
    }

    // inserting data into matrix\

    this->edgesValues = new int[edgesNumber];

    int dataIndex = 0;
    int edgeValueIndex = 0;

    for (int i = 0; i < edgesNumber; i++) {
        //    auto value = data[dataIndex];

        this->matrix[data[dataIndex]][i] = -1; // inserting edge origin
        dataIndex++;

        this->matrix[data[dataIndex]][i] = 1; // inserting edge destination
        dataIndex++;

        this->edgesValues[edgeValueIndex] = data[dataIndex]; // inserting edge value into table

        dataIndex++;
        edgeValueIndex++;
    }

    this->density = ((2 * this->edgesNumber * 100) / (this->nodesNumber * (this->nodesNumber - 1)));
}

IncidenceMatrix::IncidenceMatrix(const size_t & nodeNumber_, const size_t &edgeNumber_)
{
    this->nodesNumber = nodeNumber_;
    this->edgesNumber = edgeNumber_;

    matrix = new int*[this->nodesNumber];

    for(int i = 0; i < this->nodesNumber; i++)
    {
        this->matrix[i] = new int [this->edgesNumber];

        for(int j = 0; j < this->edgesNumber; j++)
            this->matrix[i][j] = 0;
    }

    this->edgesValues = new int [this->edgesNumber]{-1};

    this->density = ((2 * this->edgesNumber * 100) / (this->nodesNumber * (this->nodesNumber - 1)));
}

IncidenceMatrix::~IncidenceMatrix()
{
    if(this->matrix != nullptr)
    {
        for(int i = 0; i < this->nodesNumber; i++)
        {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;

        delete[] this->edgesValues;

        edgesNumber = 0;
        nodesNumber = 0;
    }
}

void IncidenceMatrix::addEdge(const size_t &source, const size_t &destination, const size_t &cost)
{
    this->matrix[source][this->usedEdges] = -1;
    this->matrix[destination][this->usedEdges] = 1;
    this->edgesValues[this->usedEdges] = cost;

    this->usedEdges++;
}

void IncidenceMatrix::displayGraph()
{
    std::cout << "  E   ";

    // printing edge list
    for (size_t i = 0; i < this->edgesNumber; i++)
    {
        std::cout << i << "      ";
    }

    std::cout << "\nV\n";

    // printing matrix
    for (size_t i = 0; i < this->nodesNumber; i++)
    {
        std::cout << i << "    ";
        for (size_t j = 0; j < this->edgesNumber; j++)
        {
            std::cout << std::setw(2) << int(this->matrix[i][j]) << "  |  ";
        }
        std::cout << "\n";
    }

    std::cout << "\nv    ";

    // printing edge values
    for (size_t i = 0; i < this->edgesNumber; i++)
    {
        std::cout << std::setw(2) << this->edgesValues[i] << "  |  ";
    }

    std::cout <<"\n";
}

size_t IncidenceMatrix::getNodesNumber()
{
    return this->nodesNumber;
}

size_t IncidenceMatrix::getEdgesNumber()
{
    return this->edgesNumber;
}

size_t IncidenceMatrix::getDensity()
{
    return this->density;
}

int** IncidenceMatrix::getMatrix()
{
    return this->matrix;
}

int* IncidenceMatrix::getEdgesValues()
{
    return this->edgesValues;
}