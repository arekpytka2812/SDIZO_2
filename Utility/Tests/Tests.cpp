#include "Tests.h"

Tests::Tests()
{
    timer = new Timer();
    fm = new FileManager();

    currentNodesNumber = 0;
    currentDensity = 0;
}

Tests::~Tests()
{
    delete timer;
    delete fm;
}

void Tests::MST()
{


    auto source = rand() % nodesNumber[currentNodesNumber];
    auto destination = rand() % nodesNumber[currentNodesNumber];

    while(source == destination)
        destination = rand() % nodesNumber[currentNodesNumber];



}

void Tests::shortestPath()
{

}

void Tests::allTests()
{

}
