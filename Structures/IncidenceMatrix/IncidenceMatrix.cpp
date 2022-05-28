#include "IncidenceMatrix.h"

IncidenceMatrix::IncidenceMatrix(const size_t & nodeNumber_, const size_t &edgeNumber_, const size_t *data):
    nodeNumber(nodeNumber_), edgeNumber(edgeNumber_)
{
    // initializing matrix with zeros

    this->matrix = new int *[nodeNumber];

    for(int i = 0; i < nodeNumber; i++)
    {
        matrix[i] = new int[edgeNumber];

        for(int j = 0; j < edgeNumber; j++)
            matrix[i][j] = 0;
    }

    // inserting data into matrix\

    this->edgesValues = new int[edgeNumber];

    int dataIndex = 0;
    int edgeValueIndex = 0;

    for(int i = 0; i < edgeNumber; i++)
    {
    //    auto value = data[dataIndex];

        this->matrix[data[dataIndex]][i] = -1; // inserting edge origin
        dataIndex++;

        this->matrix[data[dataIndex]][i] = 1; // inserting edge destination
        dataIndex++;

        this->edgesValues[edgeValueIndex] = data[dataIndex]; // inserting edge value into table

        dataIndex++;
        edgeValueIndex++;
    }
}

IncidenceMatrix::~IncidenceMatrix()
{
    if(matrix != nullptr)
    {
        for(int i = 0; i < nodeNumber; i++)
        {
            delete[] this->matrix[i];
        }
        delete[] matrix;

        delete[] edgesValues;

        edgeNumber = 0;
        nodeNumber = 0;
    }
}

void IncidenceMatrix::displayMatrix()
{
    std::cout << "  E   ";

    // printing edge list
    for (size_t i = 0; i < this->edgeNumber; i++)
    {
        std::cout << i << "      ";
    }

    std::cout << "\nV\n";

    // printing matrix
    for (size_t i = 0; i < this->nodeNumber; i++)
    {
        std::cout << i << "    ";
        for (size_t j = 0; j < this->edgeNumber; j++)
        {
            std::cout << std::setw(2) << int(this->matrix[i][j]) << "  |  ";
        }
        std::cout << "\n";
    }

    std::cout << "\nv    ";

    // printing edge values
    for (size_t i = 0; i < this->edgeNumber; i++)
    {
        std::cout << std::setw(2) << this->edgesValues[i] << "  |  ";
    }

    std::cout <<"\n";
}
