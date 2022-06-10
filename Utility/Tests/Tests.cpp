#include "Tests.h"



Tests::Tests()
{
    this->timer = new Timer();

    this->fm = new FileManager();

}

Tests::~Tests()
{
    delete this->timer;
    delete this->fm;
}

void Tests::MST()
{
    // tests for Prim - list
    for(int k = 0; k < 4; k++) {

        for (int j = 0; j < 5; j++) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphGenerator(nodesNumber[j], densities[k]);

                this->listForTests = new NeighboursList(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                this->timer->startTimer();
                this->returnList = Prim::generateMST(this->listForTests, rand() % nodesNumber[j]);
                time += timer->stopTimer();

                delete this->gg;
                delete this->listForTests;
                delete this->returnList;
            }

            time /= (double)100;

            this->fm->writeToFile("Prim", "list", nodesNumber[j], densities[k], time);
        }
    }

    // tests for Prim - matrix
    for(int k = 0; k < 4; k++) {

        for (int j = 0; j < 5; j++) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphGenerator(nodesNumber[j], densities[k]);

                this->matrixForTests = new IncidenceMatrix(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                this->timer->startTimer();
                this->returnMatrix = Prim::generateMST(this->matrixForTests, rand() % nodesNumber[j]);
                time += timer->stopTimer();

                delete this->gg;
                delete this->matrixForTests;
                delete this->returnMatrix;
            }

            time /= (double)100;

            this->fm->writeToFile("Prim", "matrix",  nodesNumber[j], densities[k], time);
        }
    }

    // tests for Kruskal - list
    for(int k = 0; k < 4; k++) {

        for (int j = 0; j < 5; j++) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphGenerator(nodesNumber[j], densities[k]);

                this->listForTests = new NeighboursList(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                this->timer->startTimer();

                this->returnList = Kruskal::generateMST(this->listForTests);

                time += timer->stopTimer();

                delete this->gg;
                delete this->listForTests;
                delete this->returnList;
            }

            time /= (double)100;

            this->fm->writeToFile("Kruskal", "list", nodesNumber[j], densities[k], time);
        }
    }

    // tests for Kruskal - matrix
    for(int k = 0; k < 4; k++) {

        for (int j = 0; j < 5; j++) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphGenerator(nodesNumber[j], densities[k]);

                this->matrixForTests = new IncidenceMatrix(this->gg->getNodesNumber(),
                                                           this->gg->getEdgesNumber(),
                                                           this->gg->getData());

                this->timer->startTimer();
                this->returnMatrix = Kruskal::generateMST(this->matrixForTests);
                time += timer->stopTimer();

                delete this->gg;
                delete this->matrixForTests;
                delete this->returnMatrix;
            }

            time /= (double)100;

            this->fm->writeToFile("Kruskal", "matrix",  nodesNumber[j], densities[k], time);
        }
    }

}

void Tests::shortestPath()
{
    // tests for Bellman - list
    for(int k = 0; k < 4; k++) {

        for (int j = 0; j < 5; j++) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphGenerator(nodesNumber[j], densities[k]);

                this->listForTests = new NeighboursList(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                int source = rand() % nodesNumber[j];
                int destination = rand() % nodesNumber[j];

                while(source == destination)
                {
                    destination = rand() % nodesNumber[j];
                }

                this->timer->startTimer();
                this->returnPath = BellmanFord::findShortestPath(this->listForTests, source, destination);
                time += timer->stopTimer();

                delete this->gg;
                delete this->listForTests;
                delete this->returnPath;
            }

            time /= (double)100;

            this->fm->writeToFile("Bellman", "list", nodesNumber[j], densities[k], time);
        }
    }

    // tests for Bellman - matrix
    for(int k = 0; k < 4; k++) {

        for (int j = 0; j < 5; j++) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphGenerator(nodesNumber[j], densities[k]);

                this->matrixForTests = new IncidenceMatrix(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                int source = rand() % nodesNumber[j];
                int destination = rand() % nodesNumber[j];

                while(source == destination)
                {
                    destination = rand() % nodesNumber[j];
                }

                this->timer->startTimer();
                this->returnPath = BellmanFord::findShortestPath(this->matrixForTests, source, destination);
                time += timer->stopTimer();

                delete this->gg;
                delete this->matrixForTests;
                delete this->returnPath;
            }

            time /= (double)100;

            this->fm->writeToFile("Bellman", "matrix", nodesNumber[j], densities[k], time);
        }
    }

    // tests for Dijkstra - list
    for(int k = 0; k < 4; k++) {

        for (int j = 0; j < 5; j++) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphGenerator(nodesNumber[j], densities[k]);

                this->listForTests = new NeighboursList(this->gg->getNodesNumber(),
                                                        this->gg->getEdgesNumber(),
                                                        this->gg->getData());

                int source = rand() % nodesNumber[j];
                int destination = rand() % nodesNumber[j];

                while(source == destination)
                {
                    destination = rand() % nodesNumber[j];
                }

                this->timer->startTimer();
                this->returnPath = Dijkstra::findShortestPath(this->listForTests, source, destination);
                time += timer->stopTimer();

                delete this->gg;
                delete this->listForTests;
                delete this->returnPath;
            }

            time /= (double)100;

            this->fm->writeToFile("Dijkstra", "list", nodesNumber[j], densities[k], time);
        }
    }

    // tests for Dijkstra - matrix
    for(int k = 0; k < 4; k++) {

        for (int j = 0; j < 5; j++) {

            double time = 0;

            for (int i = 0; i < 100; i++) {

                this->gg = new GraphGenerator(nodesNumber[j], densities[k]);

                this->matrixForTests = new IncidenceMatrix(this->gg->getNodesNumber(),
                                                           this->gg->getEdgesNumber(),
                                                           this->gg->getData());

                int source = rand() % nodesNumber[j];
                int destination = rand() % nodesNumber[j];

                while(source == destination)
                {
                    destination = rand() % nodesNumber[j];
                }

                this->timer->startTimer();
                this->returnPath = Dijkstra::findShortestPath(this->matrixForTests, source, destination);
                time += timer->stopTimer();

                delete this->gg;
                delete this->matrixForTests;
                delete this->returnPath;
            }

            time /= (double)100;

            this->fm->writeToFile("Dijkstra", "matrix", nodesNumber[j], densities[k], time);
        }
    }
}

void Tests::allTests()
{
    MST();
    shortestPath();
}
