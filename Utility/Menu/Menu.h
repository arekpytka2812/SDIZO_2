#ifndef SDIZO_2_MENU_H
#define SDIZO_2_MENU_H

#include "../Tests/Tests.h"

class Menu {

    FileManager *fm = nullptr;

    GraphGenerator *gg = nullptr;

    IncidenceMatrix *matrix = nullptr;
    IncidenceMatrix *matrixResult = nullptr;

    NeighboursList *list = nullptr;
    NeighboursList *listResult = nullptr;

    Path *path = nullptr;

    void MST();
    void shortestPath();

public:
    Menu();

    void mainMenu();
};

#endif
