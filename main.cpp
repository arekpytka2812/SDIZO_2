#include "main.h"


/*
    TODO 1) create tests
    TODO 2) create menu
    TODO 3) change printing
    TODO 4) add comments
 */

int main() {

    srand(time(nullptr));

    size_t tab[] = {
            0, 1, 1,
            0, 2, 8,
            1, 2, 2,
            1, 3, 8,
            1, 4, 4,
            2, 4, 3,
            3, 4, 5,
            3, 5, 8,
            4, 5, 3
    };

    Menu menu;

    menu.mainMenu();

    return 0;
}
