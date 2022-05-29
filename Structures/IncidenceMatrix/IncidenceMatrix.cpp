#include "IncidenceMatrix.h"

IncidenceMatrix::IncidenceMatrix(const size_t & nodeNumber_, const size_t &edgeNumber_, const size_t *data):
        nodesNumber(nodeNumber_), edgesNumber(edgeNumber_)
{
    // initializing matrix with zeros

    this->matrix = new int *[nodesNumber];

    for(int i = 0; i < nodesNumber; i++)
    {
        matrix[i] = new int[edgesNumber];

        for(int j = 0; j < edgesNumber; j++)
            matrix[i][j] = 0;
    }

    // inserting data into matrix\

    this->edgesValues = new int[edgesNumber];

    int dataIndex = 0;
    int edgeValueIndex = 0;

    for(int i = 0; i < edgesNumber; i++)
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

    this->density = ((2 * this->edgesNumber * 100) / (this->nodesNumber * (this->nodesNumber - 1)));
}

IncidenceMatrix::IncidenceMatrix(const size_t &nodesNumber_, const size_t &density_)
    : nodesNumber(nodesNumber_), density(density_)
{
    // calculating number of edges
    this->edgesNumber = (this->density ) * this->nodesNumber * (this->nodesNumber - 1) / 200;
    int currentEdgeNumber = this->edgesNumber;

    // initializing matrix with zeros
    this->matrix = new int* [this->nodesNumber];

    for(int i = 0; i < this->nodesNumber; i++)
    {
        this->matrix[i] = new int[this->edgesNumber];

        for(int j = 0; j < this->edgesNumber; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // initializing edgesValues table
    this->edgesValues = new int [this->edgesNumber];

    // making graph connected
    for(int i = 0; i < this->nodesNumber; i++)
    {
        this->edgesValues[i] = rand() % 100;

        if(i != this->nodesNumber)
        {
            matrix[i][i] = -1;
            matrix[i + 1][i] = 1;
        }
        else
        {
            matrix[i][i] = -1;
            matrix[0][i] = 1;
        }

        currentEdgeNumber--;
    }

    // if there are some edge to create this loop makes it
    while(currentEdgeNumber != 0)
    {
        bool exists = false;
        auto cost = rand() % 100;
        auto source = rand() % this->nodesNumber;
        auto destination = rand() % this->nodesNumber;

        // loop prevents from making edge to the same node
        while (destination == source)
        {
            destination = rand() % this->nodesNumber;
        }

        for(int i = 0; i < this->edgesNumber - currentEdgeNumber; i++)
        {
            if(this->matrix[source][i] != 0 && this->matrix[destination][i] != 0)
            {
                exists = true;
                break;
            }
        }

        if(!exists)
        {
            this->matrix[source][this->edgesNumber - currentEdgeNumber] = -1;
            this->matrix[destination][this->edgesNumber - currentEdgeNumber]  = 1;
            this->edgesValues[this->edgesNumber - currentEdgeNumber] = cost;
            currentEdgeNumber--;
        }
    }

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

void IncidenceMatrix::displayMatrix()
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
