#include "main.h"


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

    auto gg = new GraphGenerator(6,80);

    auto list = new NeighboursList(6, 9, tab);

    list->displayList();

    Kruskal::generateMST(list)->displayList();


    return 0;
}
